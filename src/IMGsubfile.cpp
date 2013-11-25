
#include "IMGsubfile.h"
#include "IMGUnknownSubfileException.h"
#include <iostream>

IMGsubfile* IMGsubfile::factory(std::ifstream& file, int block) {
    char bytes[0x200];

    file.seekg(0x200*block, file.beg);
    file.read(bytes, 0x200);
    if (bytes[0] == 0x01) {
        if (bytes[9] == 'M' && bytes[10] == 'P' && bytes[11] == 'S') {
            return new IMGsubfile();
        }
        if (bytes[9] == 'T' && bytes[10] == 'Y' && bytes[11] == 'P') {
            return new IMGsubfile();
        }
        if (bytes[9] == 'L' && bytes[10] == 'B' && bytes[11] == 'L') {
            return new IMGsubfile();
        }
        if (bytes[9] == 'T' && bytes[10] == 'R' && bytes[11] == 'E') {
            return new IMGsubfile();
        }
        if (bytes[9] == 'R' && bytes[10] == 'G' && bytes[11] == 'N') {
            return new IMGsubfile();
        }
        char subfile[4];
        subfile[0] = bytes[9];
        subfile[1] = bytes[10];
        subfile[2] = bytes[11];
        subfile[3] = 0;
        throw IMGUnknownSubfileException(subfile);
    }
    return nullptr;
}
