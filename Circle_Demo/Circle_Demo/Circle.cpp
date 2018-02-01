#include "Circle.h"
#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(string name_, double radius_)
{
    name = name_;
    radius = radius_;
}

double Circle::Area() const
{
    return 3.141592 * radius * radius;
}

void Circle::Display() const
{
    cout << name << " is a Circle of radius "
        << radius << std::endl;
}

bool Circle::Is_Greater_Than(const Circle& other) const
{
    return this->radius > other.radius;
}

bool Circle::operator>(const Circle& other) const
{
    return this->radius > other.radius;
}

ostream& operator<<(ostream& os, const Circle& c)
{
    os << c.name << "  Radius " << c.radius;
    return os;
}

