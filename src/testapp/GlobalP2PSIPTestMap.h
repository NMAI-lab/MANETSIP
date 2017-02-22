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
 * @file GlobalP2PSIPTestMap.h
 * @author Ingmar Baumgart
 */

#ifndef __GLOBAL_DHT_TEST_MAP_H__
#define __GLOBAL_DHT_TEST_MAP_H__

#include <map>

#include <omnetpp.h>

#include <OverlayKey.h>
#include <BinaryValue.h>
#include <ManetAddress.h>

class GlobalStatistics;

struct SIPEntry
{
    IPvXAddress address;
    simtime_t endtime;
    simtime_t insertiontime;
    friend std::ostream& operator<<(std::ostream& Stream, const SIPEntry entry);
};

/**
 * Module with a global view on all currently stored DHT records (used
 * by P2PSIPTestApp).
 *
 * @author Ingmar Baumgart, Alexandre Cormier
 */
class GlobalP2PSIPTestMap : public cSimpleModule
{
public:
    GlobalP2PSIPTestMap();
    ~GlobalP2PSIPTestMap();

    /*
     * Insert a new key/value pair into global list of all currently
     * stored SIP records.
     *
     * @param id The id of the record
     * @param entry The SIP record to store
     */
    void insertEntry(const std::string& id, const SIPEntry& entry);

    /*
     * Returns entry for a given SIP id from the global list of all
     * currently stored SIP records.
     *
     * @param id The id of the record
     * @return The entry, NULL if no records was found
     */
    const SIPEntry* findEntry(const std::string& id);

    /*
     * Erase the key/value pair with the given id from the global list of
     * all currently stored SIP records.
     *
     * @param id The id of the record
     */
    void eraseEntry(const std::string& id);

    /*
     * Returns the id of a random currently stored SIP record from the global
     * list of all currently stored SIP records.
     *
     * @return The id of the record, null if the global list is empty
     */
    const std::string* getRandomId();

    size_t size() { return dataMap.size(); };

private:
    void initialize();
    void handleMessage(cMessage* msg);
    void finish();

    static const int TEST_MAP_INTERVAL = 10; /**< interval in seconds for writing periodic statistical information */

    GlobalStatistics* globalStatistics; /**< pointer to GlobalStatistics module in this node */
    std::map<std::string, SIPEntry> dataMap; /**< The map contains all currently stored DHT records */
    cMessage *periodicTimer; /**< timer self-message for writing periodic statistical information */
};

#endif
