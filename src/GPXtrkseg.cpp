
#include "GPXtrkseg.h"
#include "GPXUnknownElementException.h"

GPXtrkseg::GPXtrkseg(const pugi::xml_node trksegNode) {
    for (pugi::xml_node n: trksegNode.children()) {
        if (std::string(n.name()) == "trkpt") {
            trkpts.push_back(new GPXtrkpt(n));
        }
        else {
            throw GPXUnknownElementException(std::string("trkseg: ") + n.name());
        }
    }
}
