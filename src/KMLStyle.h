#ifndef KMLSTYLE_H
#define KMLSTYLE_H

#include "pugixml.hpp"

class KMLStyle {
public:
    KMLStyle(const pugi::xml_node styleNode);
};

#endif
