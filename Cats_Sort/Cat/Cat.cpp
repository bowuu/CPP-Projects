#include <iostream>
#include "Cat.h"

using namespace std;

bool Cat::operator>(const Cat& other) const
{
	return this->name > other.name;
}

ostream& operator<<(ostream& os, const Cat& c)
{
	os << "Cat " << c.name << 
		" DoB: " 
		<< c.date_of_birth.Day << "/"
		<< c.date_of_birth.Month << "/" 
		<< c.date_of_birth.Year <<
		" Weight: " << c.weight << endl;
	return os;
}

Cat::Cat(string name_, Date dob_, double weight_)
{
	name = name_;
	date_of_birth = dob_;
	weight = weight_;
}

Cat::~Cat()
{
}