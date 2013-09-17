
#include "KMLPlacemark.h"
#include "KMLUnknownElementException.h"

KMLPlacemark::KMLPlacemark(const pugi::xml_node placemarkNode) {
    for (pugi::xml_node n: placemarkNode.children()) {
        if (std::string(n.name()) == "name") {
            name = n.child_value();
        }
        else if (std::string(n.name()) == "description") {
            description = n.child_value();
        }
        else if (std::string(n.name()) == "TimeSpan") {
        }
        else if (std::string(n.name()) == "Style") {
            style = new KMLStyle(n);
        }
        else if (std::string(n.name()) == "Point") {
            point = new KMLPoint(n);
        }
        else if (std::string(n.name()) == "LineString") {
        }
        else {
            throw KMLUnknownElementException(std::string("Placemark: ") + n.name());
        }
    }
}
