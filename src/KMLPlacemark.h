#ifndef KMLPLACEMARK_H
#define KMLPLACEMARK_H

#include <memory>
#include "pugixml.hpp"
#include "KMLStyle.h"
#include "KMLPoint.h"

class KMLPlacemark {
public:
    KMLPlacemark(const pugi::xml_node placemark);

private:
    std::string name;
    std::string description;
    std::unique_ptr<KMLStyle> style;
    std::unique_ptr<KMLPoint> point;
};

#endif
