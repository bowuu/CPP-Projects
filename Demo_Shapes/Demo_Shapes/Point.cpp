#include "Point.h"

using namespace std;

Point::Point(int X, int Y) : x(X), y(Y)
{}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.x << "," << p.y << ")";
	return os;
}