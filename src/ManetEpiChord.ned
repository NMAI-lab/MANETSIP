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

import oversim.overlay.epichord.EpiChord;
import oversim.overlay.epichord.EpiChordFingerCache;
import oversim.overlay.epichord.EpiChordNodeList;
import oversim.common.BaseOverlay;
import oversim.common.IOverlay;


@namespace(oversim);

//
// The main module of the EpiChord implementation
//
// @author Jamie Furness edited by Frank Ockenfeld
//
simple ManetEpiChord extends EpiChord
{
    parameters:
        @class(ManetEpiChord);
}


//
// Implementation of the EpiChord KBR overlay as described in
// "EpiChord: Parallelizing the Chord Lookup Algorithm with Reactive Routing State Management" by B. Leong et al.
//
// @author Jamie Furness
//
module ManetEpiChordModules like IOverlay
{
    parameters:
        @display("i=block/network2");

    gates:
        input udpIn;   // gate from the UDP layer
        output udpOut;    // gate to the UDP layer
        input tcpIn;    // gate from the TCP layer
        output tcpOut;    // gate to the TCP layer
        input appIn;   // gate from the application
        output appOut;    // gate to the application

    submodules:
        epichord: ManetEpiChord {
            parameters:
                @display("p=60,60");
        }
        fingerCache: EpiChordFingerCache {
            parameters:
                @display("p=150,60");
        }
        successorList: EpiChordNodeList {
            parameters:
                @display("p=240,60");
        }
        predecessorList: EpiChordNodeList {
            parameters:
                @display("p=240,60");
        }
    connections allowunconnected:
        udpIn --> epichord.udpIn;
        udpOut <-- epichord.udpOut;
        appIn --> epichord.appIn;
        appOut <-- epichord.appOut;
}
