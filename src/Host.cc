#include "Host.h"

#include "ManetChord.h"

Define_Module(Host);

void Host::initialize() {
    cModule::initialize();

    // TODO: fix this and set red only if malicious
    ManetChord* overlay = dynamic_cast<ManetChord*>(this->getSubmodule("overlay"));
    if (overlay != nullptr) {
        this->par("bgColor").setStringValue("red");
    }
}
