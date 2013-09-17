
#include "KMLStyle.h"
#include "KMLUnknownElementException.h"

KMLStyle::KMLStyle(const pugi::xml_node styleNode) {
    for (pugi::xml_node n: styleNode.children()) {
        if (std::string(n.name()) == "BallonStyle") {
        }
        else if (std::string(n.name()) == "IconStyle") {
        }
        else if (std::string(n.name()) == "LableStyle") {
        }
        else if (std::string(n.name()) == "LineStyle") {
        }
        else if (std::string(n.name()) == "ListStyle") {
        }
        else if (std::string(n.name()) == "PolyStyle") {
        }
        else {
            throw KMLUnknownElementException(std::string("Style: ") + n.name());
        }
    }
}
