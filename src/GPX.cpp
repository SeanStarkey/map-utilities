
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
        else if (str.substr(0, 5) == "xmlns") {
        }
        else {
            throw GPXUnknownElementException(std::string("GPX(A): ") + str);
        }
    }

    for (pugi::xml_node n: gpxNode.children()) {
        std::string str(n.name());
        if (str == "metadata") {
        }
        else if (str == "name") {
        }
        else if (str == "desc") {
        }
        else if (str == "author") {
        }
        else if (str == "email") {
        }
        else if (str == "url") {
        }
        else if (str == "urlname") {
        }
        else if (str == "keywords") {
        }
        else if (str == "trk") {
            trks.push_back(std::unique_ptr<GPXtrk>(new GPXtrk(n)));
        }
        else if (str == "time") {
        }
        else if (str == "bounds") {
        }
        else if (str == "wpt") {
        }
        else if (str == "rte") {
        }
        else if (str == "topografix:active_point") {
        }
        else if (str == "topografix:map") {
        }
        else {
            throw GPXUnknownElementException(std::string("GPX: ") + str);
        }
    }
}
