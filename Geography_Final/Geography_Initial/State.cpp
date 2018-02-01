#include <cassert>
#include "State.h"
using namespace std;

State::State(const string& Name, const City& Capital_) : 
    name(Name), capital(Capital_.Name())
{
    Add_City(Capital_);
}

State::~State(void)
{}

void State::Add_City(const City& city)
{
    cities.push_back(city);
    cities.sort();
}

void State::Display() const
{
    cout << name << endl;
    cout << "Capital: " <<  capital << endl;
    list<City>::const_iterator c;
    c = cities.begin();
    while (c != cities.end())
    {
        cout << "  ";
        c->Display();
        cout << endl;
        ++c;
    }
    cout << endl;
}


void State::Output_XML(ofstream& outfile) const
{
    outfile << "\t<state>\n";
    outfile << "\t\t<name>\n";
    outfile << "\t\t\t" << name << "\n";
    outfile << "\t\t</name>\n";

    outfile << "\t\t<capital>\n";
    outfile << "\t\t\t" << capital << "\n";
    outfile << "\t\t</capital>\n";

    list<City>::const_iterator c;
    c = cities.begin();
    while (c != cities.end())
    {
        if (c->Name() == capital)
        {
            ++c;
            continue;
        }
        c->Output_XML(outfile);
        ++c;
    }
    cout << endl;
    outfile << "\t</state>\n";
}


