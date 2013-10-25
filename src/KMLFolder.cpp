
#include "KMLFolder.h"
#include "KMLUnknownElementException.h"

KMLFolder::KMLFolder(const pugi::xml_node folderNode) {
    for (pugi::xml_attribute a: folderNode.attributes()) {
        std::string str(a.name());
        throw KMLUnknownElementException(std::string("Folder(A): ") + str);
    }

    for (pugi::xml_node n: folderNode.children()) {
        std::string str(n.name());
        if (str == "name") {
            name = n.child_value();
        }
        else if (str == "description") {
            description = n.child_value();
        }
        else if (str == "Folder") {
            folders.push_back(std::unique_ptr<KMLFolder>(new KMLFolder(n)));
        }
        else if (str == "Placemark") {
            placemarks.push_back(std::unique_ptr<KMLPlacemark>(new KMLPlacemark(n)));
        }
        else if (str == "Style") {
            style = std::unique_ptr<KMLStyle>(new KMLStyle(n));
        }
        else {
            throw KMLUnknownElementException(std::string("Folder: ") + str);
        }
    }
}
