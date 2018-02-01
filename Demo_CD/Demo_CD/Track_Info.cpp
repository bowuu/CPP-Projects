#include <iostream>
#include <sstream>
#include <fstream>
#include "Track.h"
#include "CD.h"

using namespace std;

// Convert a string representing minutes and seconds
// into an integer representing total seconds.
// Parameter time_str will be of the form 3:45
int get_seconds(string& time_str)
{
	size_t pos = time_str.find(':');
	string minutes_str = time_str.substr(0, pos);
	string seconds_str = time_str.substr(pos + 1);
	int minutes = 0;
	int seconds = 0;
	istringstream(minutes_str) >> minutes;
	istringstream(seconds_str) >> seconds;
	return minutes * 60 + seconds;
}

// Create a Track object from the strings in an array
// passed by the caller
Track* create_track(string* info)
{
	string title = info[0];
	// Skip over any leading white space.
	while (isspace(title[0]))
	{
		title = title.substr(1);
	}
	int play_time = get_seconds(info[1]);
	string artist = info[2];
	string genre_str = info[4];
	Genre genre = Parse_Genre(genre_str);

	Track* track = new Track(title, play_time, artist, genre);
	return track;
}

// Read track info from specified CSV file.
// Create a Track object and add it to the CD
// specified by the first parameter.
void get_tracks(CD& cd, string& track_file_name)
{
	ifstream track_file;
	int count = 0;
	track_file.open(track_file_name.c_str());

	if (!track_file.is_open())
	{
		cout << "Failed to open track file "
			<< track_file_name << endl;
		return;
	}

	// Input file is open
	while (track_file.good())
	{
		int i;
		string info[5];
		for (i = 0; i < 5; ++i)
		{
			getline(track_file, info[i], ',');
			if (!track_file.good())
			{
				break;
			}
		}

		if (i == 5)
		{
			Track* track = create_track(info);
			cd.Add_Track(track);
		}
	}
}