//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package p2psipmanet.multichainTestApp;
import oversim.common.BaseApp;
import oversim.common.ITier;
simple multichainApp extends BaseApp

{
     parameters:
         @class(multichainApp);
         string identifier = default(randomIdentifier());
}


module multichainAppModules like ITier
{
    gates:
        input from_lowerTier;    // gate from the lower tier
        input from_upperTier;    // gate from the upper tier
        input udpIn;    // gate from the UDP layer
        input trace_in;    // gate for trace file commands
        input tcpIn;             // gate from the TCP layer
        output tcpOut;           // gate to the TCP layer
        output to_lowerTier;    // gate to the lower tier
        output to_upperTier;    // gate to the upper tier
        output udpOut;    // gate to the UDP layer

    submodules:
        p2psipApp: multichainApp;
    connections allowunconnected:
        from_lowerTier --> p2psipApp.from_lowerTier;
        to_lowerTier <-- p2psipApp.to_lowerTier;
        udpIn --> p2psipApp.udpIn;
        udpOut <-- p2psipApp.udpOut;
}

