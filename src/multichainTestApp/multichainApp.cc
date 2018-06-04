/*
 * multichainApp.cc
 *
 *  Created on: Jan 21, 2018
 *      Author: ran
 */



#include "multichainApp.h"
#include "/home/ran/git/multichain/src/multichain/blockchain.h"


    Define_Module(multichainApp);
    using namespace std;

    #define REGISTER_TIMER_MSG_NAME "register_timer"
    #define RESOLVE_TIMER_MSG_NAME "resolve_timer"

    blockchain* blc;
    multichainApp::multichainApp()
       {
            register_timer = NULL;
            resolve_timer = NULL;
             blc = new blockchain();
       }

    multichainApp::~multichainApp()
       {
            cancelAndDelete(register_timer);
            cancelAndDelete(resolve_timer);
            delete blc;
       }
    void multichainApp::initializeApp(int stage)
    {
       EV << "Rania initialize App \n";

       blc->initializeBlockchain();


        if (stage != MIN_STAGE_APP) return;

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

            // fetch parameters
        identifier = par("identifier");
        // initiate test message transmission
        register_timer = new cMessage(REGISTER_TIMER_MSG_NAME);
        resolve_timer = new cMessage(RESOLVE_TIMER_MSG_NAME);




    }
    void multichainApp::registerId()
    {
        EV << "Rania RegisterId\n";
        EV << "rania address" << thisNode.getIp().str();
        blc -> setAddress(thisNode.getIp().str());
        EV << "rania get address"  << blc -> getAddress() << "\n";

        P2pnsRegisterCall* registerCall = new P2pnsRegisterCall();
        registerCall->setP2pName(BinaryValue(identifier));
        registerCall->setAddress(BinaryValue(thisNode.getIp().str()));
        registerCall->setTtl(INT32_MAX);


    }

    void multichainApp::handleReadyMessage(CompReadyMessage* msg)
    {
        EV << "Rania handleReadyMessage\n";
        if (msg->getReady() && msg->getComp() == OVERLAY_COMP) {
            registerId();
        }
    }

    bool multichainApp::handleRpcCall(BaseCallMessage* msg) {
        EV << "Rania handleRpcCall\n";
        RPC_SWITCH_START(msg)
        RPC_SWITCH_END()
    }
    void multichainApp::handleRpcResponse(BaseResponseMessage* msg,
                                       const RpcState& state, simtime_t rtt)
    {
        EV << "Rania handleRpcResponse";
        RPC_SWITCH_START(msg)
                RPC_ON_RESPONSE(P2pnsRegister) {
                    EV << "[multichainApp::handleRpcResponse()]\n"
                       << "    P2PNS Register Response received: id=" << state.getId()
                       << " msg=" << *_P2pnsRegisterResponse << " rtt=" << rtt << endl;
                    break;
                }
                RPC_ON_RESPONSE(P2pnsResolve)
                {
                    EV << "[multichainApp::handleRpcResponse()]\n"
                       << "    P2PNS Resolve RPC Response received: id=" << state.getId()
                       << " msg=" << *_P2pnsResolveResponse << " rtt=" << rtt << endl;
                    break;
                }
            RPC_SWITCH_END()
    }
    void multichainApp::handleTimerEvent(cMessage* msg)
    {
        bool isResolveTimer = msg->isName(RESOLVE_TIMER_MSG_NAME);
    }

    void    multichainApp::deliver (OverlayKey &key, cMessage *msg)
    {
        EV << "Rania deliver";
    }
    void  multichainApp::forward (OverlayKey *key, cPacket **msg, NodeHandle *nextHopNode)
    {
        EV <<"Rania forward";
    }
    void    multichainApp::handleUDPMessage (cMessage *msg)
    {
        EV <<"Rania handleUDPMessage";
    }
     void     multichainApp::sendMessageToUDP (const TransportAddress &destAddr, cPacket *msg, simtime_t delay)
     {
         EV <<"Rania sendUDPMessage";
         // use callNeighborSet to get list of the ips to send to
         //http://www.oversim.org/chrome/site/doc/doxy/classBaseApp.html#a02642da2ecd1d59c8a4377876bdf48b8

     }
