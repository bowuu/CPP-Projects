#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "Cat.h"
#include "Person.h"

using namespace std;

int Get_Owners(Person** Owner_Array, int Max_Owners)
{
	int count = 0;
	ifstream infile;
	infile.open("Cat_Owners.csv");
	
	if (!infile.is_open())
	{
		cout << "Failed to open file Cat_Owners.csv\n";
		return -1;  // Error
	}
	
	// Input file is open
	while ((count < Max_Owners) && infile.good())
	{
		string junk;
		string name;
		int id;
		string last_name;
		string first_name;
		string adr1;
		string adr2;
		string city;
		string state;
		int zip_code;
		
		infile >> id;
		getline(infile, junk, ',');
		getline(infile, last_name, ',');
		getline(infile, first_name, ',');
		getline(infile, adr1, ',');
		getline(infile, adr2, ',');
		getline(infile, city, ',');
		getline(infile, state, ',');
		infile >> zip_code;
		getline(infile, junk);
		
		if (!infile.good())
		{
			break;
		}
		
		Address* adr = new Address(adr1, adr2, city, state, zip_code);
		Owner_Array[count++] = new Person(id, last_name, first_name, *adr);
	}
	if (!infile.eof())
	{
		cout << endl << "Error reading file\n";
		count = -1;
	}
	infile.close();
	return count;
	}

Person* get_owner(int owner_id, Person** owners, int owner_count)
{
	for (int i = 0; i < owner_count; ++i)
		{
		Person* p = owners[i];
		if (p->ID() == owner_id)
		{
			return p;
		}
	}
	return 0;
	}

int Get_Cats(Cat** Cat_Array, int Max_Cats, Person** owners, int owner_count)
{
	int count = 0;
	ifstream infile;
	infile.open("cats.txt");
	
	if (!infile.is_open())
	{
		cout << "Failed to open file\n";
		return -1;  // Error
	}
	
	// Input file is open
	while ((count < Max_Cats) && infile.good())
	{
		string name;
		Date dob;
		double weight;
		int owner_id;
		infile >> name;
		infile >> dob.Month;
		infile >> dob.Day;
		infile >> dob.Year;
		infile >> weight;
		infile >> owner_id;
		
		if (!infile.good())
		{
			break;
		}
		
		Person* owner = get_owner(owner_id, owners, owner_count);
		assert(owner != 0);
		Cat_Array[count++] = new Cat(name, dob, weight, owner);
	}
	if (!infile.eof())
	{
		cout << endl << "Error reading file\n";
		count = -1;
	}
	infile.close();
	return count;
}

void Display_Cats(Cat** Cat_Array, int Nr_Cats)
{
	for (int i = 0; i < Nr_Cats; ++i)
	{
		cout << *Cat_Array[i];
		cout << endl;
	}
}

int main()
{
	Cat* cats[20];
	int cat_count;
	
	Person* owners[20];
	int owner_count;
	
	cout << "This is the cat management program\n";
	owner_count = Get_Owners(owners, 20);
	cat_count = Get_Cats(cats, 20, owners, owner_count);
	Display_Cats(cats, cat_count);
	cout << endl << "Normal termination\n";
	cin.get(); // Hold window open.
	return 0;
}