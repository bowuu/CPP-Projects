#pragma once
#include <string>

using namespace std;

enum Genre { Classical, Pop, Country, Folk, Rap, Hip_Hop, Unknown };
string& ToString(const Genre& genre);
ostream& operator<<(ostream& os, const Genre& genre);
Genre Parse_Genre(const string& str);

class Track
{
private:
	string title;
	int play_time;     // Seconds
	string artist;
	Genre genre;

public:
	Track(void);
	Track(string title_, int play_time_,
		string artist_, Genre genre_);
	~Track(void);

	int Play_Time() const { return play_time; };
	void Display() const;
};