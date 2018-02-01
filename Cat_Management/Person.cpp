#include "Person.h"
using namespace std;

Person::Person(int id_,
               const string& last_name_,
               const string& first_name_,
               const Address& address_) :
    id(id_), last_name(last_name_), first_name(first_name_)
{
    address = new Address(address_);
}

Person::Person(void)
{}

Person::~Person(void)
{}

ostream& operator<<(ostream& os, const Person& person)
{
    os << person.First_Name() << " " << person.Last_Name() << endl;
    os << person.Adr();
    return os;
}
