
#ifndef LOCATION_H
#define LOCATION_H

/*
 * Represents a Latitude/Longitude location on the earth.
 */
class Location
{
public:
    virtual double getLatitude() const = 0;
    virtual double getLongitude() const = 0;
};

#endif
