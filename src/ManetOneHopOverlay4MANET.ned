//
// Copyright (C) 2006 Institut fuer Telematik, Universitaet Karlsruhe (TH)
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

package p2psipmanet;

import oversim.overlay.onehopoverlay4manet.OneHopOverlay4MANET;
import oversim.overlay.onehopoverlay4manet.OneHopOverlay4MANETCache;
import oversim.overlay.onehopoverlay4manet.OneHopOverlay4MANETNodeList;
import oversim.common.BaseOverlay;
import oversim.common.IOverlay;
import oversim.overlay.onehopoverlay4manet.OneHopOverlay4MANETNodeList;

//
// The main module of the OneHopOverlay4MANET implementation
//
// author Frank Ockenfeld
// based on EpiChord.ned, by Jamie Furness
//
simple ManetOneHopOverlay4MANET extends OneHopOverlay4MANET
{
    parameters:
        @class(ManetOneHopOverlay4MANET);
}


//
// Implementation of the OneHopOverlay4MANET KBR overlay as described in
// "OneHopOverlay4MANET: A one logicalhop overlay for MANETs and a single Chord Lookup Algorithm with Iterative Routing State Management" by Mohammad al Mojamed
//
// author Frank Ockenfeld
//
module ManetOneHopOverlay4MANETModules like IOverlay
{
    parameters:
        @display("i=block/network2;bgb=434,144");

    gates:
        input udpIn;   // gate from the UDP layer
        output udpOut;    // gate to the UDP layer
        input tcpIn;    // gate from the TCP layer
        output tcpOut;    // gate to the TCP layer
        input appIn;   // gate from the application
        output appOut;    // gate to the application

    submodules:
        onehopoverlay4manet: ManetOneHopOverlay4MANET {
            parameters:
                @display("p=60,60");
        }
        Cache: OneHopOverlay4MANETCache {
            parameters:
                @display("p=150,60");
        }
        successorList: OneHopOverlay4MANETNodeList {
            parameters:
                @display("p=240,60");
        }
        predecessorList: OneHopOverlay4MANETNodeList {
            parameters:
                @display("p=345,60");
        }
    connections allowunconnected:
        udpIn --> onehopoverlay4manet.udpIn;
        udpOut <-- onehopoverlay4manet.udpOut;
        appIn --> onehopoverlay4manet.appIn;
        appOut <-- onehopoverlay4manet.appOut;
}
