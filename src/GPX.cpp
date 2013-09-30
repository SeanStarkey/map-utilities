
#include "GPX.h"
#include "pugixml.hpp"
#include "GPXUnknownElementException.h"

GPX::GPX(std::ifstream& file) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(file);
    if (result.status != pugi::status_ok) {
        throw GPXUnknownElementException("Bad XML");
    }

    pugi::xml_node gpxNode = doc.document_element();
    if (std::string(gpxNode.name()) != "gpx") {
        throw GPXUnknownElementException("top level not gpx");
    }

    for (pugi::xml_node n: gpxNode.children()) {
        if (std::string(n.name()) == "metadata") {
        }
        else if (std::string(n.name()) == "trk") {
            trk = new GPXtrk(n);
        }
        else {
            throw GPXUnknownElementException(std::string("GPX: ") + n.name());
        }
    }
}
