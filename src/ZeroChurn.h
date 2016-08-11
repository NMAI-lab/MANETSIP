//
// Copyright (C) 2008 Institut fuer Telematik, Universitaet Karlsruhe (TH)
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
 * @file NoChurn.h
 * @author Ingmar Baumgart
 */

#ifndef __ZERO_CHURN_H_
#define __ZERO_CHURN_H_

#include <ChurnGenerator.h>

class GlobalStatistics;
class TransportAddress;

/**
 * dummy churn generator
 */

class ZeroChurn: public ChurnGenerator
{
public:
    void initialize(int stage);
    void handleMessage(cMessage* msg);
    void initializeChurn();
    ~ZeroChurn();

protected:
    void updateDisplayString();

private:
    double initialMean; //!< mean of update interval during initalization phase
    double initialDeviation; //!< deviation of update interval during initalization phase
    bool initAddMoreTerminals; //!< true, if we're still adding more terminals in the init phase
    cMessage* mobilityTimer; /**< message to schedule events */
};

#endif
