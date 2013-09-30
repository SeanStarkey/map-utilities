#ifndef GPXTRKPT_H
#define GPXTRKPT_H

#include "pugixml.hpp"

class GPXtrkpt {
public:
    GPXtrkpt(const pugi::xml_node trkptNode);

private:
    double longitude;
    double latitude;
    double elevation;
    time_t time;
};

#endif
