#ifndef KML_H
#define KML_H

#include <fstream>
#include <vector>
#include <memory>
#include "KMLFolder.h"
#include "KMLDocument.h"

class KML {
public:
    KML(std::ifstream& file);

private:
    std::vector<std::unique_ptr<KMLFolder>> folders;
    std::vector<std::unique_ptr<KMLDocument>> documents;
};

#endif
