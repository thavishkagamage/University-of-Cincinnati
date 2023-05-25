#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date {
public:
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

private:
	int day = 0;
	int month = 0;
	int year = 0;
};

std::ostream &operator<<(std::ostream& os, const Date& newDay);

#endif
