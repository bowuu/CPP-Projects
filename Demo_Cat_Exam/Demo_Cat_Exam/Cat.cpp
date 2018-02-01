#include <cstring>
#include <iostream>
#include "Cat.h"
using namespace std;

Cat::Cat(const string& name_, Date dob, double weight_, const Person* owner) :
	name(name_), date_of_birth(dob), weight(weight_), owner(owner)
{}

Cat::~Cat(void)
{
	delete owner;
}

ostream& operator<<(ostream& os, const Cat& c)
{
	os << "Cat: " << c.Name() << endl;
	os << "Owner: " << c.Owner().First_Name()
		<< " " << c.Owner().Last_Name() << endl;
	os << c.Owner().Adr();
	return os;
}