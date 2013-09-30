
#include "GPXtrkpt.h"
#include "GPXUnknownElementException.h"
#include "StringUtil.h"
#include <ctime>
#include <fstream>
#include <vector>

GPXtrkpt::GPXtrkpt(const pugi::xml_node trkptNode) {
    for (pugi::xml_attribute a: trkptNode.attributes()) {
        if (std::string(a.name()) == "lon") {
            longitude = std::strtod(a.value(), 0);
        }
        else if (std::string(a.name()) == "lat") {
            latitude = std::strtod(a.value(), 0);
        }
        else {
            throw GPXUnknownElementException(std::string("trkpt(A): ") + a.name());
        }
    }
    for (pugi::xml_node n: trkptNode.children()) {
        if (std::string(n.name()) == "ele") {
            elevation = std::strtod(n.child_value(), 0);
        }
        else if (std::string(n.name()) == "time") {
            struct tm t;
            std::string timeString = n.child_value();
            std::vector<std::string> firstSplit;
            split(timeString, 'T', firstSplit);
            std::vector<std::string> dateSplit;
            split(firstSplit[0], '-', dateSplit);
            t.tm_year = std::stoi(dateSplit[0])-1900;
            t.tm_mon = std::stoi(dateSplit[1])-1;
            t.tm_mday = std::stoi(dateSplit[2]);
            std::vector<std::string> timeSplit;
            split(firstSplit[1], ':', timeSplit);
            t.tm_hour = std::stoi(timeSplit[0]);
            t.tm_min = std::stoi(timeSplit[1]);
            t.tm_sec = std::stoi(timeSplit[2]);
            time = mktime(&t);
        }
        else {
            throw GPXUnknownElementException(std::string("trkpt: ") + n.name());
        }
    }
}
