#include "Show_Cat.h"

Show_Cat::Show_Cat(const string& name_, Date dob, double weight_,
	const Person* owner_, const string& breed_,	const string& id) :
	Cat(name_, dob, weight_, owner_)
{
	breed = breed_;
	registration_id = id;
}

void Show_Cat::Display(std::ostream& os) const
{
	os << "Cat: " << name << endl;
	os << "Breed: " << breed << endl;
	os << "Registration ID: " << registration_id << endl;
	os << "Weight: " << weight << endl;
}

Show_Cat::~Show_Cat()
{
}
