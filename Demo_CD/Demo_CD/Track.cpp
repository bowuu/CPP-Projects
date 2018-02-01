#include <iostream>
#include "Track.h"

Track::Track(string title_, int play_time_,	string artist_, 
	Genre genre_) :

	title(title_), play_time(play_time_), artist(artist_), genre(genre_)
{}

Track::~Track(void)
{}

void Track::Display() const
{
	cout.fill('0');
	cout << title << endl;
	cout << "\tPlay time: " << (play_time / 60) << ":";
	cout.width(2);
	cout << (play_time % 60) << endl;
	cout << "\tArtist: " << artist << endl;
	cout << "\tGenre: " << genre << endl;
}

string& ToString(const Genre& genre)
{
	string* str;
	switch (genre)
	{
	case Classical: str = new string("Classical"); break;
	case Pop: str = new string("Pop"); break;
	case Country: str = new string("Country"); break;
	case Folk: str = new string("Folk"); break;
	case Rap: str = new string("Rap"); break;
	case Hip_Hop: str = new string("Hip_Hop"); break;
	default: str = new string("Unknown"); break;
	}
	return *str;
}

ostream& operator<<(ostream& os, const Genre& genre)
{
	os << ToString(genre);
	return os;
}

Genre Parse_Genre(const string& str)
{
	if (str == "Classical") return Classical;
	if (str == "Pop") return Pop;
	if (str == "Country") return Country;
	if (str == "Folk") return Folk;
	if (str == "Rap") return Rap;
	if (str == "Hip_Hop") return Hip_Hop;
	return Unknown;
}