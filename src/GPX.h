#ifndef GPX_H
#define GPX_H

#include <fstream>
#include <vector>
#include <memory>
#include "GPXtrk.h"

class GPX {
public:
    GPX(std::ifstream& file);

private:
    std::vector<std::unique_ptr<GPXtrk>> trks;
};

#endif
