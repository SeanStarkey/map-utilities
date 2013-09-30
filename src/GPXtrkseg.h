#ifndef GPXTRKSEG_H
#define GPXTRKSEG_H

#include <vector>
#include "pugixml.hpp"
#include "GPXtrkpt.h"

class GPXtrkseg {
public:
    GPXtrkseg(const pugi::xml_node trksegNode);

private:
    std::vector<GPXtrkpt*> trkpts;
};

#endif
