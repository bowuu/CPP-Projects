#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;

class City
{
private:
    string name;

public:
    City(const string& name);
    string Name() const {return name;};
    void Display() const { std::cout << name; };
    bool operator<(const City& other) const;
    void Output_XML(std::ofstream& outfile) const;
};
