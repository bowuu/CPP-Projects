#pragma once
#include <string>
using std::string;

class Address
{
private:
    string street_address;
    string address2;
    string city;
    string state;
    int zip_code;

public:
    // Constructor
    Address(string Street_Address,
            string Address2,
            string City,
            string State,
            int Zip_Code);

    Address(void) {};
    string Street_Address() const {return street_address;};
    string Address2() const {return address2;};
    string City() const {return city;};
    string State() const {return state;};
    int Zip_Code() const {return zip_code;};
};

std::ostream& operator<<(std::ostream& os, const Address& address);
