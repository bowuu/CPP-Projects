#pragma once
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
	void Display() const;

	string Name() const { return name; };
	Date Date_of_Birth() const { return date_of_birth; };
	double Weight() const { return weight; };

	~Cat(void);
};