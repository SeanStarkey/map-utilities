
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

    for (pugi::xml_attribute a: gpxNode.attributes()) {
        std::string str(a.name());
        if (str == "version") {
        }
        else if (str == "creator") {
        }
        else if (str == "xsi:schemaLocation") {
        }
        else if (str == "xmlns") {
        }
        else if (str == "xmlns:gpxtpx") {
        }
        else if (str == "xmlns:gpxx") {
        }
        else if (str == "xmlns:xsi") {
        }
        else {
            throw GPXUnknownElementException(std::string("GPX(A): ") + str);
        }
    }

    for (pugi::xml_node n: gpxNode.children()) {
        std::string str(n.name());
        if (str == "metadata") {
        }
        else if (str == "trk") {
            trk = new GPXtrk(n);
        }
        else {
            throw GPXUnknownElementException(std::string("GPX: ") + str);
        }
    }
}
