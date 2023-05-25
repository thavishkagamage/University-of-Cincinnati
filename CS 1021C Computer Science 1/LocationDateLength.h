#ifndef LOCATIONDATELENGTH_H
#define LOCATIONDATELENGTH_H

#include "Date.h"
#include "Location.h"

class LocationDateLength {

public:
	LocationDateLength() {
		
	}

	LocationDateLength(Date itlDate, Location itlLoc) {
		date = itlDate;
		loc = itlLoc;
	}

	Date getDate() const;
	Location getLocation() const;
	int getLength() const;
	void setLength(int newTime);

private:
	Date date;
	Location loc;
	int length = 0;

};

int operator-(const LocationDateLength& ldl1, const LocationDateLength ldl2);

#endif
