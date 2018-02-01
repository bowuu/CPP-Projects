#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	cout << "This is the Shapes program\n\n";
	Point pt(10, 12);

	Circle* c1 = new Circle("C1", pt, 6);
	c1->Display(cout);
	cout << "Area of " << c1->Name() << " is "
		<< c1->Area() << endl;

	Circle* c2 = new Circle("C2", pt, 10);
	c2->Display(cout);
	cout << "Area of " << c2->Name() << " is "
		<< c2->Area() << endl;

	if (*c1 < *c2)
	{
		cout << c1->Name() << " is smaller than " << c2->Name() << endl;
	}
	cout << endl;

	Rectangle* r1 = new Rectangle("R1", pt, 3, 5);
	r1->Display(cout);
	cout << "Area of " << r1->Name() << " is "
		<< r1->Area() << endl;

	Rectangle* r2 = new Rectangle("R2", pt, 4, 4);
	r2->Display(cout);
	cout << "Area of " << r2->Name() << " is "
		<< r2->Area() << endl;

	if (*r1 < *r2)
	{
		cout << r1->Name() << " is smaller than " << r2->Name() << endl;
	}
	else
	{
		cout << r1->Name() << " is not smaller than " << r2->Name() << endl;
	}
	cout << endl;

	Shape* s1 = new Circle("S1", pt, 10);
	s1->Display(cout);
	cout << "Area of " << s1->Name() << " is "
		<< s1->Area() << endl;
	cout << endl;

	Shape* s2 = new Rectangle("S2", pt, 3, 5);
	s2->Display(cout);
	cout << "Area of " << s2->Name() << " is "
		<< s2->Area() << endl;
	cout << endl;

	if (*s2 < *s1)
	{
		cout << s2->Name() << " is smaller than " << s1->Name() << endl;
	}
	else
	{
		cout << s2->Name() << " is not smaller than " << s1->Name() << endl;
	}
	cout << endl;

	cout << "Normal termination\n";
	cin.get();
	cin.get();
	return 0;
}
