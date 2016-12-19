//
//  Copyright (C) 2006,2007 Christoph Sommer <christoph.sommer@informatik.uni-erlangen.de>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

package p2psipmanet.simulations;

import inet.world.radio.ChannelControl;
import oversim.common.TierDummy;
import p2psipmanet.Host;
import p2psipmanet.Clusterhead;
import p2psipmanet.DummyUnderlayConfigurator;
import p2psipmanet.ZeroChurn;

import oversim.common.GlobalObserver;


network Hierarchical
{
    parameters:
        double hosts;
        double clusters;
        

    submodules:
        channelControl: ChannelControl;
        host[hosts]: Host;
        ch_host[clusters]: Clusterhead;
        underlayConfigurator: DummyUnderlayConfigurator{ //warning: this submodule must have this exact name for UnderlayConfiguratorAccess to work. (ugh).
            @display("p=70,130");
        }
        churnGenerator: ZeroChurn {
            @display("p=70,210,column");
        }
        globalObserver: GlobalObserver {
            @display("p=70,50");
        }
}
