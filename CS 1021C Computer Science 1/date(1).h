#ifndef __DATE_H
#define __DATE_H

#include <iostream>

// Put Date struct declaration here.
class Date {
public: 
	int day{0}, month{0}, year{0};
};

std::ostream &operator<<(std::ostream &os, Date d);
#endif
