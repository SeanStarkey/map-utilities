
#include "KMLDocument.h"
#include "KMLUnknownElementException.h"

KMLDocument::KMLDocument(const pugi::xml_node documentNode) {
    for (pugi::xml_attribute a: documentNode.attributes()) {
        std::string str(a.name());
        throw KMLUnknownElementException(std::string("Document(A): ") + str);
    }

    for (pugi::xml_node n: documentNode.children()) {
        std::string str(n.name());
        if (str == "name") {
            name = n.child_value();
        }
        else {
            throw KMLUnknownElementException(std::string("Document: ") + str);
        }
    }
}
