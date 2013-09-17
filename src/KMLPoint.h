#ifndef KMLPOINT_H
#define KMLPOINT_H

#include "pugixml.hpp"

class KMLPoint {
public:
    KMLPoint(const pugi::xml_node pointNode);

private:
    double latitude;
    double longitude;
    double elevation;
};

#endif
