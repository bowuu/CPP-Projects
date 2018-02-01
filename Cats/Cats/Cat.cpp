#include <iostream>
#include "Cat.h"

Cat::Cat(string name_, Date dob_, double weight_)
{
	name = name_;
	date_of_birth = dob_;
	weight = weight_;
}

void Cat::Display() const
{
	cout << "Cat: " << name << "  ";
	cout << "DoB: "
		<< date_of_birth.Month << "/"
		<< date_of_birth.Day << "/"
		<< date_of_birth.Year << "  ";
	cout << "Weight: " << weight;
}

Cat::~Cat(void)
{
}