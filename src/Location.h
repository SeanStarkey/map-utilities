
#ifndef LOCATION_H
#define LOCATION_H

/*
 * Represents a Latitude/Longitude location on the earth.
 */
class Location
{
public:
    int latitudeDegrees;
    int latitudeMinutes;
    int latitudeSeconds;
    bool northHemisphere;

    int longitudeDegrees;
    int longitudeMinutes;
    int longitudeSeconds;
    bool eastHemisphere;

    double getLatitude() const;
    double getLongitude() const;
};

#endif
