#include "adoptable.h"
#include <string>

bool Adoptable::hasRestrictions(std::string &restrictions) { return false; }
bool Turtle::hasRestrictions(std::string& restrictions) { 
    restrictions = "Adopter must be at least 21 years old.";
    return true; 
}

AdoptableType Adoptable::getType()const {
    return type;
};
bool Adoptable::hasShot()const {
    return has_shots;
}
std::string Adoptable::getFirstName() const {
    return first_name;
};
std::string Adoptable::getLastName() const {
    return last_name;
};

void Adoptable::print() {
  std::string restrictions{""};
  std::cout << "First name: " << first_name << "\n";
  std::cout << "Last name: " << last_name << "\n";
  std::cout << "Has Shots?: " << (has_shots ? "Yes" : "No") << "\n";
  std::cout << "Adoptable Since: " << adoptable_since << "\n";
  if (hasRestrictions(restrictions)) {
    std::cout << "Restrictions: " << restrictions << "\n";
  }
} 