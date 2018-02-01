#include "Circle.h"

Circle::Circle(double r)
{
	radius = r;
}

double Circle::Area()
{
	return 3.141592 * radius * radius;

}