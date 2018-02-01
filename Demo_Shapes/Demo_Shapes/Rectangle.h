#pragma once
#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;

class Rectangle : public Shape
{
private:
	//string name;
	//Point center;
	int width;
	int height;
public:
	Rectangle(string Name, Point Center, int W, int H);
	//string Name() const {return name;};
	//Point Center() const {return center;};
	int Width() const { return width; };
	int Height() const { return height; };

	double Area() const { return width*height; };
	//bool operator<(const Rectangle& rhs) const {return Area() < rhs.Area();};
	void Display(ostream& os) const;
};
