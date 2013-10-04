
#include "KMLPoint.h"
#include "StringUtil.h"
#include "KMLUnknownElementException.h"

KMLPoint::KMLPoint(const pugi::xml_node pointNode) {
    for (pugi::xml_attribute a: pointNode.attributes()) {
        std::string str(a.name());
        throw KMLUnknownElementException(std::string("Point(A): ") + str);
    }

    for (pugi::xml_node n: pointNode.children()) {
        std::string str(n.name());
        if (str == "altitudeMode") {
        }
        else if (str == "coordinates") {
            std::vector<std::string> elems;
            split(n.child_value(), ',', elems);
            char* pos;
            latitude = std::strtod(elems[0].c_str(), &pos);
            longitude = std::strtod(elems[1].c_str(), &pos);
            elevation = std::strtod(elems[2].c_str(), &pos);
        }
        else {
            throw KMLUnknownElementException(std::string("Point: ") + str);
        }
    }
}
