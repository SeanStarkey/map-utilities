
#include "KMLStyle.h"
#include "KMLUnknownElementException.h"

KMLStyle::KMLStyle(const pugi::xml_node styleNode) {
    for (pugi::xml_attribute a: styleNode.attributes()) {
        std::string str(a.name());
        throw KMLUnknownElementException(std::string("Style(A): ") + str);
    }

    for (pugi::xml_node n: styleNode.children()) {
        std::string str(n.name());
        if (str == "BallonStyle") {
        }
        else if (str == "IconStyle") {
        }
        else if (str == "LableStyle") {
        }
        else if (str == "LineStyle") {
        }
        else if (str == "ListStyle") {
        }
        else if (str == "PolyStyle") {
        }
        else {
            throw KMLUnknownElementException(std::string("Style: ") + str);
        }
    }
}
