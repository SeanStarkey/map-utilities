
#include "LocationDegMinSec.h"
#include <math.h>

LocationDegMinSec::LocationDegMinSec(const int latDeg, const int latMin, const int latSec,
                                     const int lonDeg, const int lonMin, const int lonSec)
{
    latitudeDegrees = latDeg;
    latitudeMinutes = latMin;
    latitudeSeconds = latSec;
    longitudeDegrees = lonDeg;
    longitudeMinutes = lonMin;
    longitudeSeconds = lonSec;
}

LocationDegMinSec::LocationDegMinSec(const double latitude, const double longitude)
{
    // if (latitude < 0)
    //     northHemisphere = false;
    // else
    //     northHemisphere = true;

    double latWork = fabs(latitude);
    latitudeDegrees = floor(latWork);
    latWork = latWork - latitudeDegrees;
    latWork = latWork * 60.0;
    latitudeMinutes = floor(latWork);
    latWork = latWork - latitudeMinutes;
    latWork = latWork * 60.0;
    latWork = latWork + 0.5;
    latitudeSeconds = floor(latWork);

    // if (longitude < 0)
    //     eastHemisphere = false;
    // else
    //     eastHemisphere = true;

    double longWork = fabs(longitude);
    longitudeDegrees = floor(longWork);
    longWork = longWork - longitudeDegrees;
    longWork = longWork * 60.0;
    longitudeMinutes = floor(longWork);
    longWork = longWork - longitudeMinutes;
    longWork = longWork * 60.0;
    longWork = longWork + 0.5;
    longitudeSeconds = floor(longWork);

}

double LocationDegMinSec::getLatitude() const
{
    int sign = (latitudeDegrees < 0) ? -1 : 1;
    return sign * (fabs(latitudeDegrees) + (latitudeMinutes/60.0) + (latitudeSeconds/(60.0*60.0)));
}

double LocationDegMinSec::getLongitude() const
{
    int sign = (longitudeDegrees < 0) ? -1 : 1;
    return sign * (fabs(longitudeDegrees) + (longitudeMinutes/60.0) + (longitudeSeconds/(60.0*60.0)));
}
