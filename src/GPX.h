#ifndef GPX_H
#define GPX_H

#include <fstream>
#include "GPXtrk.h"

class GPX {
public:
    GPX(std::ifstream& file);

private:
    GPXtrk* trk;
};

#endif
