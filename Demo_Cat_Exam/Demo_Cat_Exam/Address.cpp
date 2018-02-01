#include <iostream>
#include <string.h>
#include "Address.h"

using namespace std;

Address::Address(string Street_Address, string Address2, 
	string City, string State, int Zip_Code) :
	street_address(Street_Address), address2(Address2), city(City),
	state(State), zip_code(Zip_Code)
{}

ostream& operator<<(ostream& os, const Address& adr)
{
	os.fill('0');
	os << adr.Street_Address();
	
	if (adr.Address2().size() > 0)
	{
		os << ", " << adr.Address2();
	}
	os << endl;
	os << adr.City() << ", " << adr.State() << " ";
	os.width(5);
	os << adr.Zip_Code() << endl;
	return os;
}