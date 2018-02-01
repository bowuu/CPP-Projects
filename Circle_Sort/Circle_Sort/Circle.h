#pragma once
#include <iostream>
#include <string>
using namespace std;
class Circle
{
private:
	string name;
	double radius;

public:
	Circle(string Name, double Radius);
    Circle() {};
	string Name() const { return name; };
	double Radius() const { return radius; };
	void Display() const;
	double Area() const;

    bool Is_Greater_Than(const Circle& other) const;
    bool operator>(const Circle& other) const;


    friend ostream& operator<<(ostream& os, const Circle& c);
};




