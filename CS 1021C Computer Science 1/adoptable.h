#ifndef __ADOPTABLE_H
#define __ADOPTABLE_H

#include "date.h"
#include <string>

enum AdoptableType {
	ALL,
	TURTLE,
	CAT,
	DOG,
};
class Adoptable {
public:
	Adoptable (double weight,
		bool has_shots,
		Date adoptable_since,
		const std::string& first_name,
		const std::string& last_name,
		AdoptableType type): weight(weight), has_shots(has_shots),
		adoptable_since(adoptable_since), first_name(first_name),
		last_name(last_name), type(type){};

  virtual bool hasRestrictions(std::string &restrictions);

  void print();

  AdoptableType getType() const;

  bool hasShot() const;

  std::string getFirstName() const;
  std::string getLastName() const;

private:
	double weight;
	bool has_shots;
	std::string first_name;
	std::string last_name;
	Date adoptable_since;
	AdoptableType type;
};

class Turtle : public Adoptable {
public:
	Turtle(double weight,
		bool has_shots,
		Date adoptable_since,
		const std::string first_name,
		const std::string last_name) : Adoptable(weight,
			has_shots,
			adoptable_since,
			first_name,
			last_name, TURTLE) {}
	bool hasRestrictions(std::string& restrictions);
};

class Dog : public Adoptable {
public:
	Dog(double weight,
		bool has_shots,
		Date adoptable_since,
		const std::string first_name,
		const std::string last_name) : Adoptable(weight,
			has_shots, 
			adoptable_since,
			first_name,
			last_name, DOG){}
};

class Cat : public Adoptable {
public:
	Cat(double weight,
		bool has_shots,
		Date adoptable_since,
		const std::string first_name,
		const std::string last_name) : Adoptable(weight,
			has_shots,
			adoptable_since,
			first_name,
			last_name, CAT) {}
};

#endif