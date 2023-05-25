#include "Date.h"
#include <iostream>

/*
getDay

returns the day value of a date

input: none
output: the int, day

*/
int Date::getDay() const{
	return day;
}

/*
getMonth

returns the month value of a date

input: none
output: the int, month

*/
int Date::getMonth() const{
	return month;
}

/*
getYear

returns the year value of a date

input: none
output: the int, year

*/
int Date::getYear() const{
	return year;
}

/*
setDay

alters the day value of a date

input: an int, newDay
output: none, but the day value is changed

*/
void Date::setDay(int newDay) {
	day = newDay;
}

/*
setMonth

alters the month value of a date

input: an int, newMonth
output: none, but the month value is changed

*/
void Date::setMonth(int newMonth) {
	month = newMonth;
}

/*
setYear

alters the year value of a date

input: an int, newYear
output: none, but the year value is changed

*/
void Date::setYear(int newYear) {
	year = newYear;
}

/*
operator <<

prints out a formatted date

input: an ostream, os, and a Date, newDay
output: an ostream reading as a formatted date

*/
std::ostream &operator<<(std::ostream& os, const Date& newDay) {
	os << newDay.getYear() << "-" << newDay.getMonth() << "-" << newDay.getDay();
	return os;
}