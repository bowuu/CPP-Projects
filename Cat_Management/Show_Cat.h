#pragma once
#include <iostream>
#include <string>
#include "cat.h"

using namespace std;

class Show_Cat : public Cat
{
private:
	std::string breed;
	std::string registration_id;

public:
	Show_Cat(const std::string& name_, Date dob, double weight_,
		const Person* owner_, const std::string& breed_, 
		const std::string& id);
	std::string Breed() const { return breed; };
	std::string Registration_ID() const { return registration_id; };
	void Display(ostream& os) const;
	~Show_Cat(void);
};
