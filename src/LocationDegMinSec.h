
#ifndef LOCATIONDEGMINSEC_H
#define LOCATIONDEGMINSEC_H

#include "Location.h"

class LocationDegMinSec : public Location
{
private:
    int latitudeDegrees;
    int latitudeMinutes;
    int latitudeSeconds;

    int longitudeDegrees;
    int longitudeMinutes;
    int longitudeSeconds;

public:
    LocationDegMinSec(const int latitudeDeg,
                      const int latitudeMin,
                      const int latitudeSec,
                      const int longitudeDeg,
                      const int longitudeMin,
                      const int longitudeSec);
    LocationDegMinSec(const double latitude, const double longitude);
    double getLatitude() const;
    double getLongitude() const;
};

#endif
