#include "Circle.h"
#include "Shape.h"

using namespace std;

Circle::Circle(const string& Name, const Point& Center, int Radius) :
	Shape(Name, Center), radius(Radius)
{}

void Circle::Display(ostream& os) const
{
	os << "Circle: " << name << ", "
		<< "Center: " << center << ", "
		<< "Radius: " << radius << endl;
}
