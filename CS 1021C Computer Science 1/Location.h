#ifndef LOCATION_CPP
#define LOCATION_CPP


class Location {
public:
	double getLatitude() const;
	double getLongitude() const;
	void setLatitude(double newLat);
	void setLongitude(double newLong);

private:
	double latitude = 0;
	double longitude = 0;
};

#endif
