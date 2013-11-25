
#ifndef IMGSUBFILE_H
#define IMGSUBFILE_H

#include <fstream>

class IMGsubfile {
public:
    static IMGsubfile* factory(std::ifstream& file, int block);
};

#endif
