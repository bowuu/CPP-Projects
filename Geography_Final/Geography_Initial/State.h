#pragma once
#include <string>
#include <list>
#include <fstream>
#include "City.h"
using std::string;

class State
{
private:
    string name;
    string capital;
    std::list<City> cities;
public:
    State(const string& Name, const City& Capital_);
    ~State(void);
    void Add_City(const City& city);
    void Display() const;
    string Name() const {return name;};
    string Capital() const {return capital;};

    void Output_XML(std::ofstream& outfile) const;
};
