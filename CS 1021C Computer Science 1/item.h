#ifndef __BEADEDBAG_ITEM_HPP
#define __BEADEDBAG_ITEM_HPP

#include <string>

class Item {
public:
  Item(const std::string &item_name);
  std::string getName();
  bool isEqual(Item other);

private:
  std::string m_name;
};

#endif