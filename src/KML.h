#ifndef KML_H
#define KML_H

#include <fstream>
#include <vector>
#include "KMLFolder.h"
#include "KMLDocument.h"

class KML {
public:
    KML(std::ifstream& file);

private:
    std::vector<KMLFolder*> folders;
    std::vector<KMLDocument*> documents;
};

#endif
