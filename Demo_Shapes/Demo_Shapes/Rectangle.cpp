#include "Shape.h"
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string Name, Point Center, int W, int H) :
	Shape(Name, Center), width(W), height(H)
{}


void Rectangle::Display(ostream& os) const
{
	os << "Rectangle: " << name << ", "
		<< "Center: " << center << ", "
		<< "Width: " << width << ", "
		<< "Height: " << height << endl;
}
