#ifndef KMLFOLDER_H
#define KMLFOLDER_H

#include <vector>
#include "KMLPlacemark.h"
#include "KMLStyle.h"
#include "pugixml.hpp"

class KMLFolder {
public:
    KMLFolder(const pugi::xml_node folderNode);

private:
    std::string name;
    std::string description;
    std::vector<KMLFolder*> folders;
    std::vector<KMLPlacemark*> placemarks;
    KMLStyle* style;
};

#endif
