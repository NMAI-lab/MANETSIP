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
 * @file Chord.cc
 * @author Markus Mauch, Ingmar Baumgart
 */

#include <GlobalStatistics.h>
#include <Comparator.h>
#include <BootstrapList.h>
#include <GlobalParameters.h>
#include <NeighborCache.h>

#include <ChordFingerTable.h>
#include <ChordSuccessorList.h>
#include <ChurnGenerator.h>

#include "SimpleInfo.h"
#include "Chord.h"
#include "ManetChord.h"

namespace oversim {

using namespace std;

Define_Module(ManetChord);


void ManetChord::changeState(int toState)
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

        // initialize predecessor pointer
        predecessorNode = NodeHandle::UNSPECIFIED_NODE;

        // initialize finger table and successor list
        initializeFriendModules();

        updateTooltip();

        // debug message
        if (debugOutput) {
            EV << "[Chord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered INIT stage"
            << endl;
        }

        ////////////////////////////////////////// changes from chord module
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

        ////////////////////////////////////////// end changes from chord module

        getParentModule()->getParentModule()->bubble("Enter INIT state.");
        break;

    case JOIN:
        state = JOIN;

        // initiate join process
        cancelEvent(join_timer);
        // workaround: prevent notificationBoard from taking
        // ownership of join_timer message
        take(join_timer);
        scheduleAt(simTime(), join_timer);

        // debug message
        if (debugOutput) {
            EV << "[ManetChord::changeState() @ " << thisNode.getIp()
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
        break;

    case READY:
        state = READY;

        setOverlayReady(true);

        // initiate stabilization protocol
        cancelEvent(stabilize_timer);
        scheduleAt(simTime() + stabilizeDelay, stabilize_timer);

        // initiate finger repair protocol
        cancelEvent(fixfingers_timer);
        scheduleAt(simTime() + fixfingersDelay,
                   fixfingers_timer);

        // initiate predecessor check
        cancelEvent(checkPredecessor_timer);
        if (checkPredecessorDelay > 0) {
            scheduleAt(simTime() + checkPredecessorDelay,
                       checkPredecessor_timer);
        }
        cout<< "[Chord::READY] " << thisNode.getIp()<<" "<<simTime()<<endl;
        // debug message
        if (debugOutput) {
            EV << "[Chord::changeState() @ " << thisNode.getIp()
            << " (" << thisNode.getKey().toString(16) << ")]\n"
            << "    Entered READY stage"
            << endl;
        }
        getParentModule()->getParentModule()->bubble("Enter READY state.");
        break;
    }
}


}; //namespace
