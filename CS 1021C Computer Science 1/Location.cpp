#include "Location.h"


/*
getLatitude

returns the latitude of a location

input: none
output: a double

*/
double Location::getLatitude() const {
	return latitude;
}

/*
getLongitude

returns the longitude of a location

input: none
output: a double

*/
double Location::getLongitude() const {
	return longitude;
}

/*
setLatitude

alters the Latitude value of a location

input: a double, newLat
output: none, but the latitude is changed

*/
void Location::setLatitude(double newLat) {
	latitude = newLat;
}

/*
setLongitude

alters the Longitude value of a location

input: a double, newLong
output: none, but the longitude is changed

*/
void Location::setLongitude(double newLong) {
	longitude = newLong;
}