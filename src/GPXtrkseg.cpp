
#include "GPXtrkseg.h"
#include "GPXUnknownElementException.h"

GPXtrkseg::GPXtrkseg(const pugi::xml_node trksegNode) {
    for (pugi::xml_attribute a: trksegNode.attributes()) {
        std::string str(a.name());
        throw GPXUnknownElementException(std::string("trkseg: ") + str);
    }

    for (pugi::xml_node n: trksegNode.children()) {
        std::string str(n.name());
        if (str == "trkpt") {
            trkpts.push_back(new GPXtrkpt(n));
        }
        else {
            throw GPXUnknownElementException(std::string("trkseg: ") + str);
        }
    }
}
