#pragma once
#include <string>
#include "Address.h"

using std::string;

class Person
{
private:
	int id;
	string last_name;
	string first_name;
	Address* address;
	
public:
	Person(int id_,	const string& last_name_, const string& first_name_, const Address& address_);
	
	Person(void);
	int ID() const { return id; };
	string Last_Name() const { return last_name; };
	string First_Name() const { return first_name; };
	Address Adr() const { return *address; };
	~Person(void);
};

std::ostream& operator<<(std::ostream& os, const Person& person);