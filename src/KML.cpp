
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

    for (pugi::xml_node n: kmlNode.children()) {
        if (std::string(n.name()) == "Folder") {
            folders.push_back(new KMLFolder(n));
        }
        else if (std::string(n.name()) == "Document") {
            documents.push_back(new KMLDocument(n));
        }
        else {
            throw KMLUnknownElementException(std::string("KML: ") + n.name());
        }
    }
}
