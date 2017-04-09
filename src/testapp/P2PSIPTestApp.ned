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

package p2psipmanet.testapp;

import oversim.common.BaseApp;
import oversim.common.ITier;


//
// Simple module of the P2PSIP test application
//
// @author Alexandre Cormier
//
simple P2PSIPTestApp extends BaseApp
{
    parameters:
        @class(P2PSIPTestApp);
        string identifier = default(randomIdentifier());
        double testInterval @unit(s) = default(5s);    // time interval for DHT operations (put/get/modify)
        bool withChallenge = default(true);
        bool activeNetwInitPhase;    // send messages when network is in init phase?
}


//
// Compound module for a simple P2PSIP test application
//
// @author Gregoire Menuel, Ingmar Baumgart, Alexandre Cormier
//
module P2PSIPTestAppModules like ITier
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
        p2psipApp: P2PSIPTestApp;
    connections allowunconnected:
        from_lowerTier --> p2psipApp.from_lowerTier;
        to_lowerTier <-- p2psipApp.to_lowerTier;
        udpIn --> p2psipApp.udpIn;
        udpOut <-- p2psipApp.udpOut;
}

