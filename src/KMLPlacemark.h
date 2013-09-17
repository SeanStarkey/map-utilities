#ifndef KMLPLACEMARK_H
#define KMLPLACEMARK_H

#include "pugixml.hpp"
#include "KMLStyle.h"
#include "KMLPoint.h"

class KMLPlacemark {
public:
    KMLPlacemark(const pugi::xml_node placemark);

private:
    std::string name;
    std::string description;
    KMLStyle* style;
    KMLPoint* point;
};

#endif
