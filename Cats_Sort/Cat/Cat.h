#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int Day;
	int Month;
	int Year;
};

class Cat
{
private:
	string name;
	Date date_of_birth;
	double weight;

public:
	Cat(string name_, Date dob_, double weight_);

	Cat() {};
	string Name() const { return name; };

	bool operator>(const Cat& other) const;

	friend ostream& operator<<(ostream& os, const Cat& c);

	~Cat(void);
};