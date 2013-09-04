
#ifndef LOCATIONDEG_H
#define LOCATIONDEG_H

#include "Location.h"

class LocationDeg : public Location
{
private:
    double latitude;
    double longitude;

public:
    LocationDeg(const double latitude, const double longitude);

    virtual double getLatitude() const;
    virtual double getLongitude() const;
};

#endif
