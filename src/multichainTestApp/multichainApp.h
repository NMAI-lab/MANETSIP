/*
 * multichainApp.h
 *
 *  Created on: Jan 21, 2018
 *      Author: ran
 */

#ifndef MULTICHAINAPP_H_
#define MULTICHAINAPP_H_
#include <BaseApp.h>

    class multichainApp: public BaseApp {
        protected:
            virtual void     sendMessageToUDP (const TransportAddress &destAddr, cPacket *msg, simtime_t delay);
        public:
               multichainApp();
               virtual ~multichainApp();
               void initializeApp(int stage);
               void registerId();
               virtual void handleReadyMessage(CompReadyMessage* msg);
               bool handleRpcCall(BaseCallMessage* msg);
               void handleRpcResponse(BaseResponseMessage* msg, const RpcState& state, simtime_t rtt);
               virtual void handleTimerEvent(cMessage* msg);
               virtual void     deliver (OverlayKey &key, cMessage *msg);
               virtual void     forward (OverlayKey *key, cPacket **msg, NodeHandle *nextHopNode);
               virtual void     handleUDPMessage (cMessage *msg);
               // parameters
               const char* identifier;
               bool withChallenge;

               bool debugOutput; /**< debug output yes/no?*/
               double mean; //!< mean time interval between sending test messages
               double deviation; //!< deviation of time interval
               bool activeNetwInitPhase; //!< is app active in network init phase?

               // statistics
               int numSent; /**< number of sent packets*/
               int numGetSent; /**< number of get sent*/
               int numGetError; /**< number of false get responses*/
               int numGetSuccess; /**< number of false get responses*/
               int numPutSent; /**< number of put sent*/
               int numPutError; /**< number of error in put responses*/
               int numPutSuccess; /**< number of success in put responses*/

               cMessage *register_timer, *resolve_timer;
               bool nodeIsLeavingSoon; //!< true if the node is going to be killed shortly

               static const int DHTTESTAPP_VALUE_LEN = 20;
    };
#endif /* MULTICHAINAPP_H_ */
