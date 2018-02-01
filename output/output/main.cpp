#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	ofstream outfile;
	string outfilename;

	cout << "This program writes a short text file ";
	cout << "called test.txt\n";

	cout << "Name fo output file?";
	getline(cin, outfilename);

	outfile.open(outfilename);

	outfile << "Here is the first line of the text file\n";
	outfile << "Here is the second line\n";
	outfile << "Here is the third and final line\n";
	outfile.close();
	
	cout << "File " << outfilename << " written\n";

	cin.get();
	return 0;
}