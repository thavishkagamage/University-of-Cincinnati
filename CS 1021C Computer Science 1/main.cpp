#include "beadedbag.h"
#include "item.h"
#include <cassert>
#include <fstream>
#include <iostream>

/*
 * data_available
 *
 * Determine whether there is data available to read from _file_.
 *
 * input: The file to check for available data.
 * output: true if _file_ has data to read; false, otherwise.
 */
bool data_available(std::ifstream &file) {
  return (EOF != file.peek() && 0 == std::iscntrl(file.peek()));
}

/*
 * open_file
 *
 * Open the filename named by _filename_ with the std::ifstream
 * _file_.
 *
 * input: The name of the file to open.
 * output: _file_ is opened with _filename_.
 *         true if the file named _filename_ could be opened; false,
 *         otherwise.
 */
bool open_file(const std::string &filename, std::ifstream &file) {
  file.open(filename);
  return file.is_open();
}

/*
 * read_item_name
 *
 * Read the name of an item from _file_ and store it in _item_name_.
 *
 * input: The std::ifstream from which to read.
 * output: _item_name_ contains the name of the item read from _file_.
 *         true if an item name could be read; false, otherwise.
 */
bool read_item_name(std::ifstream &file, std::string &item_name) {
  return !!std::getline(file, item_name);
}

int main() {

  if (Item{"Testing"}.getName() != "Testing") {
    std::cout << "Oops: Your Item::getName() function does not appear to work "
                 "correctly!\n";
    exit(EXIT_FAILURE);
  }

  if (!Item{"Omega Speedmaster"}.isEqual(Item{"Omega Speedmaster"})) {
    std::cout << "Oops: Your Item::isEqual does not appear to work correctly "
                 "(Test 1)!\n";
    exit(EXIT_FAILURE);
  }

  if (Item{"Shooting Brake"}.isEqual(Item{"Boeing 787"})) {
    std::cout << "Oops: Your Item::isEqual does not appear to work correctly "
                 "(Test 2)!\n";
    exit(EXIT_FAILURE);
  }

  std::ifstream item_file;
  BeadedBag bb;
  assert(open_file("items.txt", item_file));

  while (data_available(item_file)) {
    std::string item_name;
    assert(read_item_name(item_file, item_name));
    Item item{item_name};
    bb.insert(item);
  }

  if (!bb.contains(Item{"Ghostbusters VHS"})) {
    std::cout << "Oops: My beaded bag does not contains a Ghostbusters DVD, "
                 "but it should!\n";
    exit(EXIT_FAILURE);
  }

  if (bb.contains(Item{"Blackhawk CD"})) {
    std::cout
        << "Oops: My beaded bag contains a Blackhawk CD, but it should not!\n";
    exit(EXIT_FAILURE);
  }

  if (bb.size() != 10) {
    std::cout << "Oops: The bag's size does not match the expected size (" << bb.size() << " != 10).\n";
    exit(EXIT_FAILURE);
  }
  std::cout << "Success\n";

  return 0;
}