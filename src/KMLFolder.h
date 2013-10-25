#ifndef KMLFOLDER_H
#define KMLFOLDER_H

#include <vector>
#include <memory>
#include "KMLPlacemark.h"
#include "KMLStyle.h"
#include "pugixml.hpp"

class KMLFolder {
public:
    KMLFolder(const pugi::xml_node folderNode);

private:
    std::string name;
    std::string description;
    std::vector<std::unique_ptr<KMLFolder>> folders;
    std::vector<std::unique_ptr<KMLPlacemark>> placemarks;
    std::unique_ptr<KMLStyle> style;
};

#endif
