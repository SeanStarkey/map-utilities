
#include "Location.h"

double Location::getLatitude() const
{
    return (northHemisphere ? 1 : -1) * (latitudeDegrees + (latitudeMinutes/60.0) + (latitudeSeconds/(60.0*60.0)));
}

double Location::getLongitude() const
{
    return (eastHemisphere ? 1 : -1) * (longitudeDegrees + (longitudeMinutes/60.0) + (longitudeSeconds/(60.0*60.0)));
}

