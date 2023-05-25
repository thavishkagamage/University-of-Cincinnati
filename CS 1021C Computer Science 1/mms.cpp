
#include "mms.h"
#include <string>
#include <vector>
/*
* Input: none 
* output: it will return the size of the adoptables member variable std::vector
* inventorySize will returns the total number of adoptables in the MMS.
*/
int MMS::inventorySize() {
	return adoptables.size();
}
/*
* Input: looking for animals with and without shots
* The inventorySizeByShots function will count the number
* of animals in the adoptables and return whether it has shotted.
* Output: return the number of adoptables in the shelter that have had their shots and have not had their shots.
*/
int MMS::inventorySizeByShots(bool has_shots) const {
	int count = 0;
	for (auto& animal : adoptables) {
		if (animal->hasShot() == has_shots) {
			count = count + 1;
		}
	}
	return count;
};
/*
* input: the type of animal
* output: the inventorySizeByType will return the total number of adoptables in the MMS. 
* For any other value of type, this function returns the number of adoptables in the MMS 
* with that specific type.
*/
int MMS::inventorySizeByType(AdoptableType type) const{
	if (type == ALL) {
		return adoptables.size();
	}
	else {
		int count = 0;
		for (auto& animal : adoptables) {
			if (animal->getType() == type) {
				count = count + 1;
			}
		}
		return count;
	}
}
/*
* input: search for animals with or without restrictions
* output: the inventorySizeByRestrictions function will return the number of adoptables in the 
* MMS that have adoption restrictrions. If has_restrictions is false, this function returns the number
* of adoptables in the MMS that do not have adoption restrictions.
*/
int MMS::inventorySizeByRestrictions(bool has_restrictions) const {
	int count = 0;
	std::string temp;
	for (auto& animal : adoptables) {
		if (animal->hasRestrictions(temp) == has_restrictions) {
			count = count + 1;
		}
	}
	return count;
}
/*
* input: none
* output: the function animalsInInventory will return a std::vector of std::strings - 
* one for each adoptable in the MMS. The contents of the std::string in the std::vector
* will be the names of the adoptables (their first and last names separated by a space).
*/
std::vector<std::string> MMS::animalsInInventory() const {
	std::vector<std::string> names;
	for (auto& animal : adoptables) {
		names.push_back(animal->getFirstName() + " " + animal -> getLastName());
	}
	return names;
}