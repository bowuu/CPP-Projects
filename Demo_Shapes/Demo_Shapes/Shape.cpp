#include "Shape.h"

using namespace std;

Shape::Shape(const string& Name, const Point& Center) :
	name(Name), center(Center)
{}

void Shape::Display(ostream& os) const
{
	os << "Shape: " << name << ", "
		<< "Center: " << center << endl;
}