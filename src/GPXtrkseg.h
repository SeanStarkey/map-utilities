#ifndef GPXTRKSEG_H
#define GPXTRKSEG_H

#include <vector>
#include <memory>
#include "pugixml.hpp"
#include "GPXtrkpt.h"

class GPXtrkseg {
public:
    GPXtrkseg(const pugi::xml_node trksegNode);

private:
    std::vector<std::unique_ptr<GPXtrkpt>> trkpts;
};

#endif
