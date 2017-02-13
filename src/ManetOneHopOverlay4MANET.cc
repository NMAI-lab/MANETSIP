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

/**
 * @file ManetOneHopOverlay4MANET.cc
 * @author Frank Ockenfeld
 */

#include <GlobalStatistics.h>
#include <BootstrapList.h>
#include <IterativeLookup.h>

#include "OneHopOverlay4MANETNodeList.h"
#include "OneHopOverlay4MANETCache.h"
#include "OneHopOverlay4MANET.h"
#include "OneHopOverlay4MANETIterativeLookup.h"
#include <ChurnGenerator.h>

#include "SimpleInfo.h"
#include "OneHopOverlay4MANET.h"
#include "ManetOneHopOverlay4MANET.h"

namespace oversim {

using namespace std;

Define_Module(ManetOneHopOverlay4MANET);


void ManetOneHopOverlay4MANET::changeState(int toState)
{
    //
    // Defines tasks to be executed when a state change occurs.
    //

    SimpleInfo* info;

    switch (toState) {
    case INIT:
        state = INIT;

        setOverlayReady(false);

        // initialize successor and predecessor lists
        initializeFriendModules();

        updateTooltip();

        // debug message
        if (debugOutput) {
            EV << "[OneHopOverlay4MANET::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered INIT stage"
            << endl;
        }

        ////////////////////////////////////////// changes from onehopoverlay4manet module
        // create meta information
        //FIXME: typeID is zero but should allow different values for different types of Hosts. config parameter?
        //int32_t typeID =0;
        //FIXME: how to set nodetype context? (see churngenerator.h)
        //cObject** type_context = NULL;

        //note: module info should be that of containing host module.

        info = new SimpleInfo(0, getParentModule()->getParentModule()->getId(), NULL);
        //entry = new SimpleNodeEntry(this, NULL, NULL, 0, 0);
        //info->setEntry(entry);

        //add node to Peer list
        globalNodeList->addPeer(thisNode.getIp(), info);

        ////////////////////////////////////////// end changes from onehopoverlay4manet module
        // initiate stabilize process
        cancelEvent(stabilize_timer);
        scheduleAt(simTime() + stabilizeDelay, stabilize_timer);

        getParentModule()->getParentModule()->bubble("Enter INIT state.");
        break;


    case JOIN:
        state = JOIN;

        setOverlayReady(true);

        // initiate cache flush protocol for old entries
        cancelEvent(cache_timer);
        scheduleAt(simTime() + cacheFlushDelay, cache_timer);

        // debug message
        if (debugOutput) {
            EV << "[ManetOneHopOverlay4MANET::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered JOIN stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter JOIN state.");

        break;

    case READY:
        state = READY;

        //setOverlayReady(true);

        // initiate join process
        cancelEvent(join_timer);
        // workaround: prevent notificationBoard from taking
        // ownership of join_timer message
        take(join_timer);
        scheduleAt(simTime() + joinDelay, join_timer);

        // debug message
        if (debugOutput) {
            EV << "[OneHopOverlay4MANET::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered READY stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter READY state.");
        break;
    }
}


}; //namespace
