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

package p2psipmanet;

import inet.networklayer.autorouting.ipv4.HostAutoConfigurator;
import inet.networklayer.IManetRouting;
//import inet.nodes.inet.WirelessHost;
import inet.nodes.inet.NodeBase;
import inet.networklayer.manetrouting.OLSR;


import inet.base.NotificationBoard;
import inet.linklayer.ppp.PPPInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.udp.UDP;
import inet.transport.tcp.TCP;
import oversim.common.BootstrapList;
import oversim.common.CryptoModule;
import oversim.common.IOverlay;
import oversim.common.ITier;
import oversim.common.NeighborCache;
import inet.linklayer.loopback.LoopbackInterface;


//
// Host that participates in the overlay over a MANET
//
// @author Markus Mauch, Bernhard Heep, Alan Davoust
//
module Clusterhead extends NodeBase
{
    parameters:
        string overlayType; // overlay protocol compound module to use
        string tier1Type; // tier 1 application to use
        string tier2Type; // tier 2 module to use
        string tier3Type; // tier 3 module to use
        int numTiers; // number of tiers
        //string routingFile = default("");
        @node;
        @display("bgb=537,472;i=device/cellphone");
        networkLayer.configurator.networkConfiguratorModule = ""; // parameter for IPv4NetworkLayer (the default value of networkLayer)
        string routingProtocol = default("inet.networklayer.manetrouting.OLSR");
        IPForward = true;
        
        numRadios = 2;
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");
        wlan[1].radio.carrierFrequency = 5GHz;
        wlan[1].transmitterPower = 100mW; // power used for transmission of messages (in mW)
        //wlan[1].thermalNoise = -110dBm; // base noise level (dBm)
        //wlan[1].sensitivity = -85dBm;
        


    gates:
        input overlayNeighborArrowIn[]; // incoming gate for visualizing overlay neighborship with connection arrows
        output overlayNeighborArrowOut[]; // incoming gate for visualizing overlay neighborship with connection arrows
        

    submodules:
        tier3: <tier3Type> like ITier {
            parameters:
                @display("p=96,44");
       }
        tier2: <tier2Type> like ITier {
            parameters:
                @display("p=202,44");
        }
        tier1: <tier1Type> like ITier {
            parameters:
                @display("p=317,58");
        }
        overlay: <overlayType> like IOverlay {
            parameters:
                @display("p=422,119");
        }
        udp: UDP {
            parameters:
                @display("p=390,225");
        }
        tcp: TCP {
            parameters:
                @display("p=255,225");
        }
        
        neighborCache: NeighborCache { //needed along with bootstraplist
            parameters:
                @display("p=179,305");
        }

        bootstrapList: BootstrapList {
            parameters:
                @display("p=168,311");
        }
        cryptoModule: CryptoModule { //needed with neighborcache
            parameters:
                @display("p=158,248");
        }
        ac_wlan: HostAutoConfigurator {
            @display("p=171,335");
        }

        manetrouting: <routingProtocol> like IManetRouting {

            @display("p=471,287");
        }
    connections allowunconnected:
        //networkLayer.ifOut++ --> lo0.upperLayerIn;
        //lo0.upperLayerOut --> networkLayer.ifIn++;

        tier1.to_lowerTier --> overlay.appIn if numTiers>0;
        tier1.from_lowerTier <-- overlay.appOut if numTiers>0;
        tier1.udpOut --> udp.appIn++ if numTiers>0;
        udp.appOut++ --> tier1.udpIn if numTiers>0;
        tier1.tcpOut --> tcp.appIn++ if numTiers>0;
        tcp.appOut++ --> tier1.tcpIn if numTiers>0;

        tier2.to_lowerTier --> tier1.from_upperTier if numTiers > 1;
        tier2.from_lowerTier <-- tier1.to_upperTier if numTiers > 1;
        tier2.udpOut --> udp.appIn++ if numTiers>1;
        udp.appOut++ --> tier2.udpIn if numTiers>1;
        tier2.tcpOut --> tcp.appIn++ if numTiers>1;
       tcp.appOut++ --> tier2.tcpIn if numTiers>1;

       tier3.to_lowerTier --> tier2.from_upperTier if numTiers > 2;
        tier3.from_lowerTier <-- tier2.to_upperTier if numTiers > 2;
        tier3.udpOut --> udp.appIn++ if numTiers>2;
        udp.appOut++ --> tier3.udpIn if numTiers>2;
        tier3.tcpOut --> tcp.appIn++ if numTiers>2;
        tcp.appOut++ --> tier3.tcpIn if numTiers>2;

        overlay.udpOut --> udp.appIn++;
        overlay.udpIn <-- udp.appOut++;

        overlay.tcpOut --> tcp.appIn++;
        overlay.tcpIn <-- tcp.appOut++;

        bootstrapList.udpOut --> udp.appIn++;
        bootstrapList.udpIn <-- udp.appOut++;

        udp.ipOut --> networkLayer.transportIn++;
        udp.ipIn <-- networkLayer.transportOut++;

        tcp.ipOut --> networkLayer.transportIn++;
        tcp.ipIn <-- networkLayer.transportOut++;

        manetrouting.to_ip --> networkLayer.transportIn++;
        manetrouting.from_ip <-- networkLayer.transportOut++;

        // connections to network outside
        for i=0..sizeof(pppg)-1 {
            pppg[i] <--> ppp[i].phys;
            ppp[i].upperLayerOut --> networkLayer.ifIn++;
            ppp[i].upperLayerIn <-- networkLayer.ifOut++;
        }

}





