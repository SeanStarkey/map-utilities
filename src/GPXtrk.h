#ifndef GPXTRK_H
#define GPXTRK_H

#include <vector>
#include "pugixml.hpp"
#include "GPXtrkseg.h"

class GPXtrk {
public:
    GPXtrk(const pugi::xml_node trkNode);

private:
    std::string name;
    std::vector<GPXtrkseg*> trksegs;
};

#endif
