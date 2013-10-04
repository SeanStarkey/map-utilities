
#include "GPXtrk.h"
#include "GPXUnknownElementException.h"

GPXtrk::GPXtrk(const pugi::xml_node trkNode) {
    for (pugi::xml_attribute a: trkNode.attributes()) {
        std::string str(a.name());
        throw GPXUnknownElementException(std::string("trk: ") + str);
    }

    for (pugi::xml_node n: trkNode.children()) {
        std::string str(n.name());
        if (str == "name") {
            name = n.child_value();
        }
        else if (str == "trkseg") {
            trksegs.push_back(new GPXtrkseg(n));
        }
        else {
            throw GPXUnknownElementException(std::string("trk: ") + str);
        }
    }
}
