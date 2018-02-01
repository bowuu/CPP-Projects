#include <iostream>
#include <fstream>
#include <sstream>
#include "CD_Info.h"
#include "Track_Info.h"

using namespace std;

// Create a CD object from one line of a CSV file 
// containing CD info.
CD* create_CD(string* info)
{
	string title = info[0];

	// Skip over any leading spaces
	while (isspace(title[0]))
	{
		title = title.substr(1);
	}

	string id = info[1];
	string artist = info[2];
	string manufacturer = info[3];
	int year;

	istringstream(info[4]) >> year;
	Recording_Technology recording_technology;

	recording_technology = Parse_Rec_Tech(info[5]);

	CD* cd = new CD(title, id, artist, manufacturer,
		year, recording_technology);

	// Add code to get track info
	string track_file_name = info[6];
	get_tracks(*cd, track_file_name);
	return cd;
}

// Read a CSV file of CD info and create the corresponding CDs
// at location specified by the caller.  
// Return count of CDs created.
int get_CDs(CD** cds, int max)
{
	ifstream cds_file;
	string cds_filename;
	int count = 0;

	// Get filename for CD Info file
	cout << "Collection Filename: ";
	getline(cin, cds_filename);
	cds_file.open(cds_filename.c_str());

	if (!cds_file.is_open())
	{
		cout << "Failed to open file " << cds_filename << endl;
		return -1;// Error
	}

	// Input file is open
	while (cds_file.good() && (count < max))
	{
		int i;
		string info[7];
		for (i = 0; i < 7; ++i)
		{
			getline(cds_file, info[i], ',');
			if (!cds_file.good())
			{
				break;
			}
		}

		if (i == 7)
		{
			CD* next_cd = create_CD(info);
			next_cd->Display();     // Temporary test code
			cds[count] = next_cd;
			++count;
		}
	}

	if (cds_file.eof())
	{
		cout << endl << "End of file \n";
	}
	else
	{
		cout << endl << "Error reading file\n";
	}
	cds_file.close();
	return count;
}