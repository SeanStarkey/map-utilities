
#include "LocationDeg.h"

LocationDeg::LocationDeg(const double lat, const double lon)
{
    latitude = lat;
    longitude = lon;
}

double LocationDeg::getLatitude() const
{
    return latitude;
}

double LocationDeg::getLongitude() const
{
    return longitude;
}

