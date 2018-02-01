#include <fstream>
#include <iostream>
#include <string>
#include "Cat.h"

using namespace std;

// Read Cat data from a text file, set up Cat objects
// in caller's array, and return number of Cats.
// Negative count indicates error.
int Get_Cats(Cat** Cat_Array, int Max_Cats)
{
	int count = 0;
	ifstream infile;
	string name;
	Date date_of_birth;
	double weight;
	infile.open("cats.txt");

	if (!infile.is_open())
	{
		cout << "Failed to open file\n";
		return -1;	// Error
	}
	while ((count < Max_Cats) && infile.good())
	{
		char name[500];
		infile >> name;
		infile >> date_of_birth.Day;
		infile >> date_of_birth.Month;
		infile >> date_of_birth.Year;
		infile >> weight;
		
		if (!infile.good())
		{
			break;
		}
		Cat_Array[count++] = new Cat(name, date_of_birth, weight);
	}
	if (infile.eof())
	{
		cout << endl << "End of file \n";
	}
	else
	{
		cout << endl << "Error reading file\n";
		count = -1;
	}
	infile.close();
	return count;
}

void swap_cats(Cat*& c1, Cat*& c2)
{
	Cat* temp = c1;
	c1 = c2;
	c2 = temp;
}

void Sort_Cats(Cat** Cats, int nr_cats)
{
	bool swap_done = false;
	do
	{
		swap_done = false;
		for (int i = 0; i < nr_cats - 1; ++i)
		{
			if (*Cats[i] > *Cats[i + 1])
			{
				swap_cats(Cats[i], Cats[i + 1]);
				swap_done = true;
			}
		}
	} while (swap_done);
}

int main()
{
	Cat* Cats[20];
	cout << "This is program Sort_Cats\n";
	int count = -1;
	int count2;

	count = Get_Cats(Cats, 20);

	if (count < 1)
	{
		cout << "Failed to read Cats file\n";
		cin.get();
		return -1;
	}

	cout << count << " cats read\n";
	for (count2 = 0; count2 < count; ++count2) {
		cout << *Cats[count2];
	}

	Sort_Cats(Cats, count);

	cout << "\nSorted Cats:\n";
	for (count2 = 0; count2 < count; ++count2) {
		cout << *Cats[count2];
	}

	cout << "\nNormal termination\n";
	cin.get();
}