#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

std::vector<Item> bag;

// Implement the BeadedBag::size and BeadedBag::insert member functions here.

/*
* insert
* 
* If it isn't already in the bag, it takes an input and adds it to it.
* 
* input: to_insert, an Item
* output: none
*/
void BeadedBag::insert(Item to_insert) {
	bool isIn = false;
	for (int i = 0; i < bag.size(); ++i) {
		if (bag[i].isEqual(to_insert)) {
			isIn = true;
		}
	}
	if (!isIn) {
		bag.push_back(to_insert);
	}
}

/*
* size
*
* The size of the bag, or the number of goods within, is returned..
*
* input: none
* output: an integer
*/
int BeadedBag::size() {
	return bag.size();
}

// Complete the implementation of the BeadedBag::contains member function.
/*
* contains
*
* determines if an item is contained within the bag.
*
* input: an Item, maybe_contained_item
* output: a boolean that determines whether the item is in the bag or not.
*/
bool BeadedBag::contains(Item maybe_contained_item) {
	bool isIn = false;
	for (int i = 0; i < bag.size(); ++i) {
		if (bag[i].isEqual(maybe_contained_item)) {
			isIn = true;
		}
	}
	return isIn;
}