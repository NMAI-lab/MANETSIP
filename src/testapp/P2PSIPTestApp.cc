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
 * @author Ingmar Baumgart
 */

#include <IPvXAddressResolver.h>
#include <GlobalNodeListAccess.h>
#include <GlobalStatisticsAccess.h>
#include <UnderlayConfiguratorAccess.h>
#include <RpcMacros.h>
#include "CommonMessages_m.h"

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

    debugOutput = par("debugOutput");
    activeNetwInitPhase = par("activeNetwInitPhase");

    mean = par("testInterval");
    deviation = mean / 10;

    ttl = par("testTtl");

    globalNodeList = GlobalNodeListAccess().get();
    underlayConfigurator = UnderlayConfiguratorAccess().get();
    globalStatistics = GlobalStatisticsAccess().get();

    globalP2PSIPTestMap =
            dynamic_cast<GlobalP2PSIPTestMap*>(simulation.getModuleByPath(
                    "globalObserver.globalFunctions[0].function"));

    if (globalP2PSIPTestMap == NULL) {
        throw cRuntimeError("P2PSIPTestApp::initializeApp(): "
                            "GlobalP2PSIPTestMap module not found!");
    }

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

    if (mean > 0) {
        scheduleAt(simTime() + truncnormal(mean, deviation), register_timer);
        scheduleAt(simTime() + truncnormal(mean + mean / 3, deviation),
                   resolve_timer);
    }

    registerId();
}

void P2PSIPTestApp::handleRpcResponse(BaseResponseMessage* msg,
                                   const RpcState& state, simtime_t rtt)
{
    RPC_SWITCH_START(msg)
        RPC_ON_RESPONSE(DHTputCAPI) {
            handleRegisterResponse(
                    _DHTputCAPIResponse,
                    check_and_cast<P2PSIPStatsContext*>(state.getContext()));
            EV << "[P2PSIPTestApp::handleRpcResponse()]\n"
               << "    DHT Put RPC Response received: id=" << state.getId()
               << " msg=" << *_DHTputCAPIResponse << " rtt=" << rtt << endl;
            break;
        }
        RPC_ON_RESPONSE(DHTgetCAPI)
        {
            handleResolveResponse(
                    _DHTgetCAPIResponse,
                    check_and_cast<P2PSIPStatsContext*>(state.getContext()));
            EV << "[P2PSIPTestApp::handleRpcResponse()]\n"
               << "    DHT Get RPC Response received: id=" << state.getId()
               << " msg=" << *_DHTgetCAPIResponse << " rtt=" << rtt << endl;
            break;
        }RPC_SWITCH_END()
}

void P2PSIPTestApp::handleRegisterResponse(DHTputCAPIResponse* msg,
                                   P2PSIPStatsContext* context)
{
    SIPEntry entry = { context->address, simTime() + ttl, simTime() };

    if (context->measurementPhase == false) {
        // don't count response, if the request was not sent
        // in the measurement phase
        delete context;
        return;
    }

//    if (!msg->getProperlySigned()) {
//        cout << "P2PSIPTestApp: Register reached malicious node [t=" << simTime() << "]"
//             << endl;
//        delete context;
//        return;
//    }

    if (msg->getIsSuccess()) {

        //only insert key into testmap if it was successfully put.
        globalP2PSIPTestMap->insertEntry(context->id, entry);

        cout << "P2PSIPTestApp: Register Success [t=" << simTime() << "]" << endl;
        RECORD_STATS(numPutSuccess++);
        RECORD_STATS(globalStatistics->addStdDev("P2PSIPTestApp: PUT Latency (s)", SIMTIME_DBL(simTime() - context->requestTime)));

        cancelEvent(register_timer);
    } else {
        cout << "P2PSIPTestApp: Register failed [t=" << simTime() << "]" << endl;
        RECORD_STATS(numPutError++);
    }

    delete context;
}

void P2PSIPTestApp::handleResolveResponse(DHTgetCAPIResponse* msg,
                                   P2PSIPStatsContext* context)
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

    if (false) {
        //this key doesn't exist anymore in the DHT, delete it in our hashtable

        globalP2PSIPTestMap->eraseEntry(context->id);
        delete context;

        if (msg->getResultArraySize() > 0) {
            RECORD_STATS(numGetError++);
            cout << "P2PSIPTestApp: Resolve failed [t=" << simTime()
                 << "] deleted key still available" << endl;
            return;
        } else {
            RECORD_STATS(numGetSuccess++);
            cout << "P2PSIPTestApp: Resolve success [t=" << simTime() << "]" << endl;
            return;
        }
    } else {
        delete context;
        if ((msg->getResultArraySize() > 0)
                && (msg->getResult(0).getValue() == BinaryValue(entry->address.str()))) {
            RECORD_STATS(numGetSuccess++);
            cout << "P2PSIPTestApp: Resolve success [t=" << simTime() << "]" << endl;
            return;
        } else {
            cout << "P2PSIPTestApp: Resolve failed [t=" << simTime() << "] wrong value"
                 << " expected " << entry->address.str() << ", got " << msg->getResult(0).getValue() << endl;
            RECORD_STATS(numGetError++);
            return;
        }
    }

}

void P2PSIPTestApp::handleTraceMessage(cMessage* msg)
{
    char* cmd = new char[strlen(msg->getName()) + 1];
    strcpy(cmd, msg->getName());

    if (strlen(msg->getName()) < 5) {
        delete[] cmd;
        delete msg;
        return;
    }

    if (strncmp(cmd, "PUT ", 4) == 0) {
        // Generate key
        char* buf = cmd + 4;

        while (!isspace(buf[0])) {
            if (buf[0] == '\0') throw cRuntimeError(
                    "Error parsing PUT command");
            buf++;
        }

        buf[0] = '\0';
        BinaryValue b(cmd + 4);
        OverlayKey destKey(OverlayKey::sha1(b));

        // get value
        buf++;

        // build putMsg
        DHTputCAPICall* dhtPutMsg = new DHTputCAPICall();
        dhtPutMsg->setKey(destKey);
        dhtPutMsg->setValue(buf);
        dhtPutMsg->setTtl(ttl);
        dhtPutMsg->setIsModifiable(true);
        RECORD_STATS(numSent++; numPutSent++);
        sendInternalRpcCall(
                TIER1_COMP,
                dhtPutMsg,
                new P2PSIPStatsContext(globalStatistics->isMeasuring(), simTime(),
                                    identifier, thisNode.getIp()));
    } else if (strncmp(cmd, "GET ", 4) == 0) {
        // Get key
        BinaryValue b(cmd + 4);
        OverlayKey key(OverlayKey::sha1(b));

        DHTgetCAPICall* dhtGetMsg = new DHTgetCAPICall();
        dhtGetMsg->setKey(key);
        RECORD_STATS(numSent++; numGetSent++);
        sendInternalRpcCall(
                TIER1_COMP,
                dhtGetMsg,
                new P2PSIPStatsContext(globalStatistics->isMeasuring(), simTime(),
                                    identifier));
    } else {
        throw cRuntimeError("Unknown trace command; "
                            "only GET and PUT are allowed");
    }

    delete[] cmd;
    delete msg;
}

void P2PSIPTestApp::handleTimerEvent(cMessage* msg)
{
    bool isGetTimer = msg->isName(RESOLVE_TIMER_MSG_NAME);

    // schedule next timer event
    scheduleAt(simTime() + truncnormal(mean, deviation), msg);

    // do nothing if the network is still in the initialization phase
    if (((!activeNetwInitPhase) && (underlayConfigurator->isInInitPhase()))
            || underlayConfigurator->isSimulationEndingSoon()
            || nodeIsLeavingSoon) {
        return;
    } else if (isGetTimer) { //--------get test
        if (isRegistered()) {
            sendRandomResolve();
        }
    } else {
        registerId();
    }
}

void P2PSIPTestApp::sendRandomResolve()
{
    const std::string* id = globalP2PSIPTestMap->getRandomId();
    if (id == NULL) {
        return;
    }

    DHTgetCAPICall* resolveCall = new DHTgetCAPICall();
    resolveCall->setKey(OverlayKey::sha1(*id));
    RECORD_STATS(numSent++; numGetSent++);

    sendInternalRpcCall(
            TIER1_COMP,
            resolveCall,
            new P2PSIPStatsContext(globalStatistics->isMeasuring(), simTime(), *id));
}

void P2PSIPTestApp::registerId()
{
    OverlayKey destKey = OverlayKey::sha1(identifier);
    BinaryValue value(thisNode.getIp().str());

    DHTputCAPICall* dhtPutMsg = new DHTputCAPICall();
    dhtPutMsg->setKey(destKey);
    dhtPutMsg->setValue(value);
    dhtPutMsg->setTtl(ttl);
    dhtPutMsg->setIsModifiable(true);

    RECORD_STATS(numSent++; numPutSent++);
    sendInternalRpcCall(
            TIER1_COMP,
            dhtPutMsg,
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

