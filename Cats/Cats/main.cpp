#include <iostream>
#include "Cat.h"
using namespace std;

Cat* Create_Cat()
{
	string name;
	Date date_of_birth;
	double weight;
	cout << "Please enter information for new Cat\n";
	cout << "Name: ";
	cin >> name;
	cout << "Date of Birth:\n";
	cout << "   Month: ";
	cin >> date_of_birth.Month;
	cout << "   Day: ";
	cin >> date_of_birth.Day;
	cout << "   Year: ";
	cin >> date_of_birth.Year;

	cout << "Weight: ";
	cin >> weight;
	Cat* cat = new Cat(name, date_of_birth, weight);
	return cat;
}

int main()
{
	cout << "This is program Cats\n";

	Cat* Fluffy = Create_Cat();

	Fluffy->Display();
	cout << endl;

	delete Fluffy;
	Fluffy = 0;

	cin.get();    // Hold window open.
	cin.get();
	return 0;
}