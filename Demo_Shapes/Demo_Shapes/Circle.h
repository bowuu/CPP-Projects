#pragma once
#include <iostream>
#include <string>
#include "Shape.h"
#include "Point.h"

using std::string;
using std::ostream;

class Circle : public Shape
{
private:
	int radius;
	//string name;
	//Point center;

public:
	Circle(const string& Name, const Point& Center, int Radius);
	//string Name() const {return name;};
	//Point Center() const {return center;};
	int Radius() const { return radius; };
	double Area() const { return 3.14159 * radius * radius; };
	//bool operator<(const Circle& rhs) const {return Area() < rhs.Area();};
	void Display(ostream& os) const;
};
