#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using std::string;
using std::ostream;

class Shape
{
protected:
	string name;
	Point center;

public:
	Shape(const string& Name, const Point& Center);
	string Name() const { return name; };
	Point Center() const { return center; };
	virtual double Area() const = 0;
	virtual bool operator<(const Shape& rhs) const
	{
		return Area() < rhs.Area();
	};
	virtual void Display(ostream& os) const;
};