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
 * @file ManetChord.h
 * @author Markus Mauch, Ingmar Baumgart
 */

#ifndef __MANETCHORD_H_
#define __MANETCHORD_H_

#include <BaseOverlay.h>
#include <NeighborCache.h>
#include <Chord.h>


#include "ChordMessage_m.h"

/**
 * ManetChord overlay module
 *
 * Minor changes from Chord module: node registers itself to bootstraplist during INIT state.
 *
 *
 * @see BaseOverlay, Chord, ChordFingerTable, ChordSuccessorList
 */
class ManetChord : public oversim::Chord
{


protected:

    /**
     * changes node state
     *
     * @param toState state to change to
     */
    virtual void changeState(int toState);


};

#endif
