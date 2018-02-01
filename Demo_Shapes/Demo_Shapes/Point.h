#pragma once
#include <iostream>

using std::ostream;

class Point
{
private:
	int x;
	int y;

public:
	Point(int X, int Y);
	friend ostream& operator<<(ostream& os, const Point& p);
};