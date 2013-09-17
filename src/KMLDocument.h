#ifndef KMLDOCUMENT_H
#define KMLDOCUMENT_H

#include "pugixml.hpp"

class KMLDocument {
public:
    KMLDocument(const pugi::xml_node documentNode);

private:
    std::string name;
};

#endif
