#ifndef GPXTRK_H
#define GPXTRK_H

#include <vector>
#include <memory>
#include "pugixml.hpp"
#include "GPXtrkseg.h"

class GPXtrk {
public:
    GPXtrk(const pugi::xml_node trkNode);

private:
    std::string name;
    std::vector<std::unique_ptr<GPXtrkseg>> trksegs;
};

#endif
