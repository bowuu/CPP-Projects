#include <iostream>
#include <cassert>
#include "CD.h"
#include "Track.h"

using namespace std;

CD::CD(string title_, string id_, string artist_,	string manufacturer_,
	int year_,	Recording_Technology rec_tech_) :

	title(title_), id(id_), artist(artist_), manufacturer(manufacturer_),
	year(year_), rec_tech(rec_tech_), nr_tracks(0)
{}

CD::~CD()
{
}

void CD::Display() const
{
	cout.fill('0');
	cout << "CD: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Mfgr: " << manufacturer << endl;
	cout << "Year: " << year << endl;
	cout << "Recording technology: " << rec_tech << endl;

	//add code to display total play time
	cout << "Total play time: " << (Total_Play_Time() / 60) << ":";
	cout.width(2);
	cout << (Total_Play_Time() % 60) << endl;
	cout << endl;

	//add code to display each track
	for (int i = 0; i < nr_tracks; ++i)
	{
		cout << "\tTrack " << i + 1 << ": ";
		tracks[i]->Display();
		cout << endl;
	}
}

string& ToString(const Recording_Technology& rec_tech)
{
	string* str;
	switch (rec_tech)
	{
	case AAD: str = new string("AAD");  break;
	case ADD: str = new string("ADD");  break;
	case DDD: str = new string("DDD");  break;
	default: str = new string("UNK");
	}
	return *str;
}

ostream& operator<<(ostream& os, const Recording_Technology& rec_tech)
{
	os << ToString(rec_tech);
	return os;
}

void CD::Add_Track(Track* track)
{
	assert(nr_tracks < MAX_TRACKS);
	tracks[nr_tracks++] = track;
}

int CD::Total_Play_Time() const
{
	int total = 0;
	for (int i = 0; i < nr_tracks; ++i)
	{
		total += tracks[i]->Play_Time();
	}
	return total;
}

Recording_Technology Parse_Rec_Tech(const string& str)
{
	if (str.compare("AAD") == 0) return AAD;
	if (str.compare("ADD") == 0) return ADD;
	if (str.compare("DDD") == 0) return DDD;
	return UNK;
}