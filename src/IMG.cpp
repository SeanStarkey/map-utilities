
#include "IMG.h"
#include "hexdump.h"
#include "IMGsubfile.h"
#include <string.h>
#include <iostream>

IMG::IMG(std::ifstream& file) {
    char outbuffer[10240];
    char bytes[0x200];
    file.read(bytes, 0x100);
    //ptrhexdumpToStr(outbuffer, 10240, (unsigned char*)bytes, 0x100);
    //std::cout << std::endl;
    //std::cout << outbuffer;

    if (strncmp("DSKIMG", bytes+0x10, 6) != 0) {
        return;
    }

    char blockimage = bytes[0x40];

    int block = blockimage + 1;
    IMGsubfile* isf;
    do {
        isf = IMGsubfile::factory(file, block);
        block++;
    }
    while (isf != nullptr);
}
