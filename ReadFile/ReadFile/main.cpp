#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	string infilename;
	ifstream infile;
	string input_line;

	cout << "This program reads a text file \n";

	cout << "Name of the ile to read: ";
	getline(cin, infilename);

	cout << "Opening file " << infilename << endl;
	infile.open(infilename);
	cout << "File Opened";

	while (infile.good)
	{
		infile >> input_line;
		cout << input_line;
	}

	cin.get();
	cin.get();
	return 0;
}