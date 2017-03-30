//
// @author Alexandre Cormier
//

cplusplus {{
#include <CommonMessages_m.h>
}}

class BaseCallMessage;
class BaseResponseMessage;

packet SIPChallengeCall extends BaseCallMessage {
}

packet SIPChallengeResponse extends BaseResponseMessage {
    string identifier;
}
