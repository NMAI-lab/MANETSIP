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
 * @file GlobalP2PSIPTestMap.cc
 * @author Ingmar Baumgart
 */

#include <omnetpp.h>

#include <GlobalStatisticsAccess.h>

#include <DHTTestAppMessages_m.h>

#include "GlobalP2PSIPTestMap.h"

using namespace std;

Define_Module(GlobalP2PSIPTestMap);

std::ostream& operator<<(std::ostream& stream, const SIPEntry entry)
{
    return stream << "Address: " << entry.address;
}

GlobalP2PSIPTestMap::GlobalP2PSIPTestMap()
{
}

GlobalP2PSIPTestMap::~GlobalP2PSIPTestMap()
{
    dataMap.clear();
}

void GlobalP2PSIPTestMap::initialize()
{
    globalStatistics = GlobalStatisticsAccess().get();
    WATCH_MAP(dataMap);
}

void GlobalP2PSIPTestMap::finish()
{
}

void GlobalP2PSIPTestMap::insertEntry(const std::string& id, const SIPEntry& entry)
{
    Enter_Method_Silent();

    dataMap.erase(id);
    dataMap.insert(make_pair(id, entry));
}

void GlobalP2PSIPTestMap::eraseEntry(const std::string& id)
{
    dataMap.erase(id);
}

const SIPEntry* GlobalP2PSIPTestMap::findEntry(const std::string& id)
{
    std::map<std::string, SIPEntry>::iterator it = dataMap.find(id);

    if (it == dataMap.end()) {
        return NULL;
    } else {
        return &(it->second);
    }
}

const std::string* GlobalP2PSIPTestMap::getRandomId()
{
    if (size() == 0) {
        return NULL;
    }

    std::map<std::string, SIPEntry>::iterator it = dataMap.begin();
    std::advance(it, intuniform(0, size() - 1));

    return &it->first;
}


