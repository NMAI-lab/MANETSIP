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
 * @file ManetEpiChord.cc
 * @author Frank Ockenfeld
 */

#include <GlobalStatistics.h>
#include <BootstrapList.h>
#include <IterativeLookup.h>

#include "EpiChordNodeList.h"
#include "EpiChordFingerCache.h"
#include "EpiChord.h"
#include "EpiChordIterativeLookup.h"
#include <ChurnGenerator.h>

#include "SimpleInfo.h"
#include "EpiChord.h"
#include "ManetEpiChord.h"

namespace oversim {

using namespace std;

Define_Module(ManetEpiChord);


void ManetEpiChord::changeState(int toState)
{
    //
    // Defines tasks to be executed when a state change occurs.
    //


    SimpleInfo* info;
    //SimpleNodeEntry* entry;




    switch (toState) {
    case INIT:
        state = INIT;

        setOverlayReady(false);

        // initialize successor and predecessor lists
        initializeFriendModules();

        updateTooltip();

        // debug message
        if (debugOutput) {
            EV << "[EpiChord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered INIT stage"
            << endl;
        }

        ////////////////////////////////////////// changes from epichord module
        // create meta information
        //FIXME: typeID is zero but should allow different values for different types of Hosts. config parameter?
        //int32_t typeID =0;
        //FIXME: how to set nodetype context? (see churngenerator.h)
        //cObject** type_context = NULL;

        //note: module info should be that of containing host module.

        info = new SimpleInfo(0, getParentModule()->getParentModule()->getId(), NULL);
        //entry = new SimpleNodeEntry(this, NULL, NULL, 0, 0);
        //info->setEntry(entry);

        //add node to bootstrap oracle
        globalNodeList->addPeer(thisNode.getIp(), info);

        ////////////////////////////////////////// end changes from epichord module

        getParentModule()->getParentModule()->bubble("Enter INIT state.");
        break;


    case BOOTSTRAP:
        state = BOOTSTRAP;

        // initiate bootstrap process
        cancelEvent(join_timer);
        // workaround: prevent notificationBoard from taking
        // ownership of join_timer message
        take(join_timer);
        scheduleAt(simTime(), join_timer);

        // debug message
        if (debugOutput) {
            EV << "[ManetEpiChord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered BOOTSTRAP stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter JOIN state.");

        // find a new bootstrap node and enroll to the bootstrap list
        bootstrapNode = bootstrapList->getBootstrapNode(overlayId);

        // is this the first node?
        if (bootstrapNode.isUnspecified()) {
            // create new epichord ring
            assert(successorList->isEmpty());
            assert(predecessorList->isEmpty());
            bootstrapNode = thisNode;
            changeState(READY);
            updateTooltip();
        }
        break;


        /* case JOIN:
        state = JOIN;

        // initiate join process
        cancelEvent(join_timer);
        // workaround: prevent notificationBoard from taking
        // ownership of join_timer message
        take(join_timer);
        scheduleAt(simTime(), join_timer);

        // debug message
        if (debugOutput) {
            EV << "[ManetEpiChord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered JOIN stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter JOIN state.");

        // find a new bootstrap node and enroll to the bootstrap list
        bootstrapNode = bootstrapList->getBootstrapNode(overlayId);

        // is this the first node?
        if (bootstrapNode.isUnspecified()) {
            // create new chord ring
            assert(predecessorNode.isUnspecified());
            bootstrapNode = thisNode;
            changeState(READY);
            updateTooltip();
        }
        break;*/

    case READY:
        state = READY;

        setOverlayReady(true);

        // initiate stabilization protocol
        cancelEvent(stabilize_timer);
        scheduleAt(simTime() + stabilizeDelay, stabilize_timer);

        // initiate finger repair protocol
        cancelEvent(cache_timer);
        scheduleAt(simTime() + cacheFlushDelay, cache_timer);

        // debug message
        if (debugOutput) {
            EV << "[EpiChord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered READY stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter READY state.");
        break;
    }
}


}; //namespace
