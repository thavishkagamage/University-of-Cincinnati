#include <string>
#include "item.h"

Item::Item(const std::string &item_name): m_name(item_name) {}

/*
* getName
*
*returns the item's name.
*
* input: none
* output: a string value
*/
std::string Item::getName() {
  return m_name;
}

/*
* isEqual
*
* determines if an item is the same as one that has been entered.
*
* input: an Item, other_item
* output: a bool of whether the two are equal or not.
*/
bool Item::isEqual(Item other_item) {
  return m_name == other_item.getName();
}