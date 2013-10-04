
#include "KMLPlacemark.h"
#include "KMLUnknownElementException.h"

KMLPlacemark::KMLPlacemark(const pugi::xml_node placemarkNode) {
    for (pugi::xml_attribute a: placemarkNode.attributes()) {
        std::string str(a.name());
        throw KMLUnknownElementException(std::string("Placemark(A): ") + str);
    }

    for (pugi::xml_node n: placemarkNode.children()) {
        std::string str(n.name());
        if (str == "name") {
            name = n.child_value();
        }
        else if (str == "description") {
            description = n.child_value();
        }
        else if (str == "TimeSpan") {
        }
        else if (str == "Style") {
            style = new KMLStyle(n);
        }
        else if (str == "Point") {
            point = new KMLPoint(n);
        }
        else if (str == "LineString") {
        }
        else {
            throw KMLUnknownElementException(std::string("Placemark: ") + str);
        }
    }
}
