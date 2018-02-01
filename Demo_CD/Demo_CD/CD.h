#pragma once
#include <string>
#include "Track.h"

using namespace std;

enum Recording_Technology { AAD, ADD, DDD, UNK };
string& ToString(const Recording_Technology& rec_tech);
ostream& operator<<(ostream& os, const Recording_Technology& rec_tech);
Recording_Technology Parse_Rec_Tech(const string& str);

class CD
{
public:
	static const int MAX_TRACKS = 50;
private:
	string title;
	string id;
	string artist;
	string manufacturer;
	int year;
	Recording_Technology rec_tech;

	Track* tracks[MAX_TRACKS];
	int nr_tracks;

public:
	CD(void);
	CD(string title_, string id_, string artist_, string manufacturer_,
		int year_, Recording_Technology rech_tech_);
	~CD(void);

	void Display() const;

	void Add_Track(Track* track);
	int Total_Play_Time() const;
};

