#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
using std::string;

struct Date
{
    int Day;
    int Month;
    int Year;
};

class Cat
{
protected:
    string name;
    Date date_of_birth;
    double weight;
    const Person* owner;

public:
    Cat(const string& name_, Date dob, double weight_, 
        const Person* owner_);
    string Name() const { return name;};
    Date Date_of_Birth() const { return date_of_birth;};
    double Weight() const {return weight;};
    Person Owner() const {return *owner;};
	virtual void Display(std::ostream& os) const;
    ~Cat(void);
};

std::ostream& operator<<(std::ostream& os, const Cat& c);
