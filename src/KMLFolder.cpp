
#include "KMLFolder.h"
#include "KMLUnknownElementException.h"

KMLFolder::KMLFolder(const pugi::xml_node folderNode) {
    for (pugi::xml_node n: folderNode.children()) {
        if (std::string(n.name()) == "name") {
            name = n.child_value();
        }
        else if (std::string(n.name()) == "description") {
            description = n.child_value();
        }
        else if (std::string(n.name()) == "Folder") {
            folders.push_back(new KMLFolder(n));
        }
        else if (std::string(n.name()) == "Placemark") {
            placemarks.push_back(new KMLPlacemark(n));
        }
        else if (std::string(n.name()) == "Style") {
            style = new KMLStyle(n);
        }
        else {
            throw KMLUnknownElementException(std::string("Folder: ") + n.name());
        }
    }
}
