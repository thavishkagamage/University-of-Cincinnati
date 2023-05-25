#include "LocationDateLength.h"
#include "Date.h"
#include "Location.h"

/*
getDate

returns a date value

input: none
output: a date

*/
Date LocationDateLength::getDate() const{
	return date;
}

/*
getLocation

returns a Location value

input: none
output: a location

*/
Location LocationDateLength::getLocation() const {
	return loc;
}

/*
getLength

returns the length of a LocationDateLength value

input: none
output: an integer

*/
int LocationDateLength::getLength() const {
	return length;
}

/*
setLength

alters the length value of a LocationDateLength

input: an integer, newTime
output: none, but the length value changes

*/
void LocationDateLength::setLength(int newTime) {
	length = newTime;
}

/*
operator-

returns the difference between the lengths of two LDL's

input: two LDL's
output: an integer

*/
int operator-(const LocationDateLength& ldl1, const LocationDateLength ldl2) {
	return ldl1.getLength() - ldl2.getLength();
}