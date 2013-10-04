#ifndef GPX_H
#define GPX_H

#include <fstream>
#include <vector>
#include "GPXtrk.h"

class GPX {
public:
    GPX(std::ifstream& file);

private:
    std::vector<GPXtrk*> trks;
};

#endif
