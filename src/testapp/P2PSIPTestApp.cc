//
// Copyright (C) 2007 Institut fuer Telematik, Universitaet Karlsruhe (TH)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

/**
 * @file P2PSIPTestApp.cc
 * @author Ingmar Baumgart, Alexandre Cormier
 */

#include <IPvXAddressResolver.h>
#include <GlobalNodeListAccess.h>
#include <GlobalStatisticsAccess.h>
#include <UnderlayConfiguratorAccess.h>
#include <RpcMacros.h>
#include "P2PSIPTestAppMessages_m.h"

#include "GlobalP2PSIPTestMap.h"

#include "P2PSIPTestApp.h"

Define_Module(P2PSIPTestApp);

using namespace std;

#define REGISTER_TIMER_MSG_NAME "register_timer"
#define RESOLVE_TIMER_MSG_NAME "resolve_timer"

P2PSIPTestApp::~P2PSIPTestApp()
{
    cancelAndDelete(register_timer);
    cancelAndDelete(resolve_timer);
}

P2PSIPTestApp::P2PSIPTestApp()
{
    register_timer = NULL;
    resolve_timer = NULL;
}

void P2PSIPTestApp::initializeApp(int stage)
{
    if (stage != MIN_STAGE_APP) return;

    // fetch parameters
    identifier = par("identifier");
    withChallenge = par("withChallenge");

    debugOutput = par("debugOutput");
    activeNetwInitPhase = par("activeNetwInitPhase");

    mean = par("testInterval");
    if (mean <= 0) {
        throw cRuntimeError("P2PSIPTestApp::initializeApp(): testInterval should be > 0");
    }

    deviation = mean / 10;

    globalNodeList = GlobalNodeListAccess().get();
    underlayConfigurator = UnderlayConfiguratorAccess().get();
    globalStatistics = GlobalStatisticsAccess().get();

    globalP2PSIPTestMap = dynamic_cast<GlobalP2PSIPTestMap*>(simulation.getModuleByPath("globalObserver.globalFunctions[0].function"));

    if (globalP2PSIPTestMap == NULL) {
        throw cRuntimeError("P2PSIPTestApp::initializeApp(): GlobalP2PSIPTestMap module not found!");
    }

    bindToPort(1337);

    // statistics
    numSent = 0;
    numGetSent = 0;
    numGetError = 0;
    numGetSuccess = 0;
    numPutSent = 0;
    numPutError = 0;
    numPutSuccess = 0;

    //initRpcs();
    WATCH(numSent);
    WATCH(numGetSent);
    WATCH(numGetError);
    WATCH(numGetSuccess);
    WATCH(numPutSent);
    WATCH(numPutError);
    WATCH(numPutSuccess);

    nodeIsLeavingSoon = false;

    // initiate test message transmission
    register_timer = new cMessage(REGISTER_TIMER_MSG_NAME);
    resolve_timer = new cMessage(RESOLVE_TIMER_MSG_NAME);

    scheduleAt(simTime() + truncnormal(mean + mean / 3, deviation), resolve_timer);
}

void P2PSIPTestApp::handleReadyMessage(CompReadyMessage* msg)
{
    if (msg->getReady() && msg->getComp() == OVERLAY_COMP) {
        registerId();
    }
}

bool P2PSIPTestApp::handleRpcCall(BaseCallMessage* msg) {
    RPC_SWITCH_START(msg)
        RPC_ON_CALL(SIPChallenge) {
            handleChallengeCall(_SIPChallengeCall);
            return true;
        }
    RPC_SWITCH_END()
}

void P2PSIPTestApp::handleChallengeCall(SIPChallengeCall* msg) {
    SIPChallengeResponse* response = new SIPChallengeResponse();
    response->setIdentifier(identifier);
    sendRpcResponse(msg, response);
}

void P2PSIPTestApp::handleRpcResponse(BaseResponseMessage* msg,
                                   const RpcState& state, simtime_t rtt)
{
    RPC_SWITCH_START(msg)
        RPC_ON_RESPONSE(P2pnsRegister) {
            handleRegisterResponse(
                    _P2pnsRegisterResponse,
                    check_and_cast<P2PSIPStatsContext*>(state.getContext()));
            EV << "[P2PSIPTestApp::handleRpcResponse()]\n"
               << "    P2PNS Register Response received: id=" << state.getId()
               << " msg=" << *_P2pnsRegisterResponse << " rtt=" << rtt << endl;
            break;
        }
        RPC_ON_RESPONSE(P2pnsResolve)
        {
            handleResolveResponse(_P2pnsResolveResponse, check_and_cast<P2PSIPStatsContext*>(state.getContext()));
            EV << "[P2PSIPTestApp::handleRpcResponse()]\n"
               << "    P2PNS Resolve RPC Response received: id=" << state.getId()
               << " msg=" << *_P2pnsResolveResponse << " rtt=" << rtt << endl;
            break;
        }
        RPC_ON_RESPONSE(SIPChallenge) {
            handleChallengeResponse(_SIPChallengeResponse, check_and_cast<P2PSIPChallengeContext*>(state.getContext()));
            break;
        }
    RPC_SWITCH_END()
}

void P2PSIPTestApp::handleRegisterResponse(P2pnsRegisterResponse* msg,
                                   P2PSIPStatsContext* context)
{
    SIPEntry entry = { context->address };

//    if (context->measurementPhase == false) {
//        // don't count response, if the request was not sent
//        // in the measurement phase
//        delete context;
//        return;
//    }

//    if (!msg->getProperlySigned()) {
//        cout << "P2PSIPTestApp: Register reached malicious node [t=" << simTime() << "]"
//             << endl;
//        delete context;
//        return;
//    }

    if (msg->getIsSuccess()) {

        //only insert key into testmap if it was successfully put.
        globalP2PSIPTestMap->insertEntry(context->id, entry);

        cout << "P2PSIPTestApp: Register success [t=" << simTime() << "]" << endl;
        RECORD_STATS(numPutSuccess++);
        RECORD_STATS(globalStatistics->addStdDev("P2PSIPTestApp: Register Latency (s)", SIMTIME_DBL(simTime() - context->requestTime)));
    } else {
        cout << "P2PSIPTestApp: Register failed [t=" << simTime() << "]" << endl;
        scheduleAt(simTime() + truncnormal(mean, deviation), register_timer);
        RECORD_STATS(numPutError++);
    }

    delete context;
}

void P2PSIPTestApp::handleResolveResponse(P2pnsResolveResponse* msg, P2PSIPStatsContext* context)
{
    if (context->measurementPhase == false) {
        // don't count response, if the request was not sent
        // in the measurement phase
        delete context;
        return;
    }

    RECORD_STATS(
            globalStatistics->addStdDev("P2PSIPTestApp: Resolve Latency (s)", SIMTIME_DBL(simTime() - context->requestTime)));

//    if (!msg->getProperlySigned()) {
//        cout << "P2PSIPTestApp: GET reached malicious node [t=" << simTime() << "]"
//             << endl;
//        delete context;
//        return;
//    }

    if (!(msg->getIsSuccess())) {
        cout << "P2PSIPTestApp: Resolve failed [t=" << simTime() << "]" << endl;
        RECORD_STATS(numGetError++);
        delete context;
        return;
    }

    const SIPEntry* entry = globalP2PSIPTestMap->findEntry(context->id);

    if (entry == NULL) {
        //unexpected key
        RECORD_STATS(numGetError++);
        cout << "P2PSIPTestApp: Resolve failed [t=" << simTime() << "] unexpected key"
             << endl;
        delete context;
        return;
    }

    if (msg->getAddressArraySize() > 0) {
        string address(msg->getAddress(0).begin(), msg->getAddress(0).end());
        if (address == entry->address.str()) {
            RECORD_STATS(numGetSuccess++);
            cout << "P2PSIPTestApp: Resolve success [t=" << simTime() << "]" << endl;
            if (withChallenge) {
                sendChallenge(context->id, entry->address);
            }
            delete context;
            return;
        } else {
            cout << "P2PSIPTestApp: Resolve failed [t=" << simTime() << "] wrong value"
                 << " expected " << entry->address.str() << ", got " << msg->getAddress(0) << endl;
            RECORD_STATS(numGetError++);
            delete context;
            return;
        }
    } else {
        cout << "P2PSIPTestApp: Resolve failed [t=" << simTime() << "] no result"
             << " expected " << entry->address.str() << endl;
        RECORD_STATS(numGetError++);
        delete context;
        return;
    }
}

void P2PSIPTestApp::handleChallengeResponse(SIPChallengeResponse* msg, P2PSIPChallengeContext* context) {
    cout << msg->getIdentifier() << " ------------------------------------------------------------------ " << context->id << endl;
    if (msg->getIdentifier() == context->id) {
        cout << "P2PSIPTestApp: Challenge success [t=" << simTime() << "]" << endl;
    } else {
        cout << "P2PSIPTestApp: Challenge failed [t=" << simTime() << "]" << endl;
    }
    delete context;
}

void P2PSIPTestApp::handleTimerEvent(cMessage* msg)
{
    bool isResolveTimer = msg->isName(RESOLVE_TIMER_MSG_NAME);

    // do nothing if the network is still in the initialization phase
    if (((!activeNetwInitPhase) && (underlayConfigurator->isInInitPhase()))
            || underlayConfigurator->isSimulationEndingSoon()
            || nodeIsLeavingSoon) {
        return;
    } else if (isResolveTimer) { //--------get test
        scheduleAt(simTime() + truncnormal(mean, deviation), msg);
        if (isRegistered()) {
            sendRandomResolve();
        }
    } else {
        registerId();
    }
}

void P2PSIPTestApp::sendChallenge(const string& id, const IPvXAddress& ipAddress) {
    TransportAddress transportAddress(ipAddress, getThisNode().getPort(), getThisNode().getNatType());
    SIPChallengeCall* challengeCall = new SIPChallengeCall();
    P2PSIPChallengeContext* context = new P2PSIPChallengeContext(id);
    sendUdpRpcCall(transportAddress, challengeCall, context);
}

void P2PSIPTestApp::sendRandomResolve()
{
    const std::string* id = globalP2PSIPTestMap->getRandomId();
    if (id == NULL) {
        return;
    }

    P2pnsResolveCall* resolveCall = new P2pnsResolveCall();
    resolveCall->setP2pName(BinaryValue(*id));

    RECORD_STATS(numSent++; numGetSent++);

    sendInternalRpcCall(
            TIER2_COMP,
            resolveCall,
            new P2PSIPStatsContext(globalStatistics->isMeasuring(), simTime(), *id));
}

void P2PSIPTestApp::registerId()
{
    P2pnsRegisterCall* registerCall = new P2pnsRegisterCall();
    registerCall->setP2pName(BinaryValue(identifier));
    registerCall->setAddress(BinaryValue(thisNode.getIp().str()));
    registerCall->setTtl(INT32_MAX);

    RECORD_STATS(numSent++; numPutSent++);
    sendInternalRpcCall(
            TIER2_COMP,
            registerCall,
            new P2PSIPStatsContext(globalStatistics->isMeasuring(), simTime(), identifier, thisNode.getIp()));
}

bool P2PSIPTestApp::isRegistered() {
    return globalP2PSIPTestMap->findEntry(identifier) != NULL;
}

void P2PSIPTestApp::handleNodeLeaveNotification()
{
    nodeIsLeavingSoon = true;
}

void P2PSIPTestApp::finishApp()
{
    simtime_t time = globalStatistics->calcMeasuredLifetime(creationTime);

    if (time >= GlobalStatistics::MIN_MEASURED) {
        // record scalar data
        globalStatistics->addStdDev("P2PSIPTestApp: Sent Total Messages/s",
                                    numSent / time);
        globalStatistics->addStdDev("P2PSIPTestApp: Sent Resolve Messages/s",
                                    numGetSent / time);
        globalStatistics->addStdDev("P2PSIPTestApp: Failed Resolve Requests/s",
                                    numGetError / time);
        globalStatistics->addStdDev("P2PSIPTestApp: Successful Resolve Requests/s",
                                    numGetSuccess / time);

        globalStatistics->addStdDev("P2PSIPTestApp: Sent Register Messages/s",
                                    numPutSent / time);
        globalStatistics->addStdDev("P2PSIPTestApp: Failed Register Requests/s",
                                    numPutError / time);
        globalStatistics->addStdDev("P2PSIPTestApp: Successful Register Requests/s",
                                    numPutSuccess / time);

        if ((numGetSuccess + numGetError) > 0) {
            globalStatistics->addStdDev(
                    "P2PSIPTestApp: Resolve Success Ratio",
                    (double) numGetSuccess
                            / (double) (numGetSuccess + numGetError));
        }
    }
}

