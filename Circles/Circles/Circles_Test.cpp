#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
	Circle c1(5);
	Circle c2(10);

	double c1_area = c1.Area();

	cout << "Area of circle c1 is " << c1_area << '\n';
	cout << "Area of circle c2 is " << c2.Area() << '\n';

	cin.get();
	return 0;
}