
#include "KML.h"
#include "pugixml.hpp"
#include "KMLUnknownElementException.h"

KML::KML(std::ifstream& file) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(file);
    if (result.status != pugi::status_ok) {
        throw KMLUnknownElementException("Bad XML");
    }

    pugi::xml_node kmlNode = doc.document_element();
    if (std::string(kmlNode.name()) != "kml") {
        throw KMLUnknownElementException("top level not kml");
    }

    for (pugi::xml_attribute a: kmlNode.attributes()) {
        std::string str(a.name());
        if (str == "xsi:schemaLocation") {
        }
        else if (str == "xmlns") {
        }
        else if (str == "xmlns:xsi") {
        }
        else {
            throw KMLUnknownElementException(std::string("KML(A): ") + str);
        }
    }

    for (pugi::xml_node n: kmlNode.children()) {
        std::string str(n.name());
        if (str == "Folder") {
            folders.push_back(std::unique_ptr<KMLFolder>(new KMLFolder(n)));
        }
        else if (str == "Document") {
            documents.push_back(std::unique_ptr<KMLDocument>(new KMLDocument(n)));
        }
        else {
            throw KMLUnknownElementException(std::string("KML: ") + str);
        }
    }
}
