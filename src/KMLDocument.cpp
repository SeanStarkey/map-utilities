
#include "KMLDocument.h"
#include "KMLUnknownElementException.h"

KMLDocument::KMLDocument(const pugi::xml_node documentNode) {
    for (pugi::xml_node n: documentNode.children()) {
        if (std::string(n.name()) == "name") {
            name = n.child_value();
        }
        else {
            throw KMLUnknownElementException(std::string("Document: ") + n.name());
        }
    }
}
