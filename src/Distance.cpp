
#include "Distance.h"
#include <math.h>
#include <iostream>
#include "Constants.h"

double distance(const Location* c1, const Location* c2)
{
    double dLat = toRadians(c1->getLatitude() - c2->getLatitude());
    double dLon = toRadians(c1->getLongitude() - c2->getLongitude());
    double lat1 = toRadians(c1->getLatitude());
    double lat2 = toRadians(c2->getLatitude());

    double halfdLatSin = sin(dLat/2.0);
    double halfdLonSin = sin(dLon/2.0);
    double a = halfdLatSin * halfdLatSin +
        halfdLonSin * halfdLonSin * cos(lat1) * cos(lat2);
    double c = 2*atan2(sqrt(a), sqrt(1-a));

    return RADIUSEARTH*c;
}
