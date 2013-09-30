
#include "GPXtrk.h"
#include "GPXUnknownElementException.h"

GPXtrk::GPXtrk(const pugi::xml_node trkNode) {
    for (pugi::xml_node n: trkNode.children()) {
        if (std::string(n.name()) == "name") {
            name = n.child_value();
        }
        else if (std::string(n.name()) == "trkseg") {
            trksegs.push_back(new GPXtrkseg(n));
        }
        else {
            throw GPXUnknownElementException(std::string("trk: ") + n.name());
        }
    }
}
