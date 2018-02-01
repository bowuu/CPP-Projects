#include <cstring>
#include <iostream>
#include "Cat.h"
using namespace std;

Cat::Cat(const string& name_, Date dob, double weight_, 
         const Person* owner) :
    name(name_), date_of_birth(dob), weight(weight_),
    owner(owner)
{}

Cat::~Cat(void) 
{
    delete owner;
}

ostream& operator<<(ostream& os, const Cat& cat)
{
    os << "Cat: " << cat.Name() << endl;
	os << "Owner: " << cat.Owner();
    return os;
}

void Cat::Display(ostream& os) const
{
	os << "Cat: " << name << endl;
	os << "Owner: " << owner->First_Name()
		<< " " << owner->Last_Name() << endl;
	os << owner->Adr();
}