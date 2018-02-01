#include <string>
#include "City.h"

City::City(const string& Name) : name(Name)
{}

bool City::operator<(const City& other) const
{
    return this->name < other.name;
}

void City::Output_XML(std::ofstream& outfile) const
{
    outfile << "\t\t<city>\n";
    outfile << "\t\t\t" << name << "\n"; 
    outfile << "\t\t</city>\n";
}

