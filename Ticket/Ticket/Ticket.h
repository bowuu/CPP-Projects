#pragma once
#include <string>
using namespace std;

struct Seat
{
	string Row;
	int  Number;
};

struct Date_Time
{
	int Day;
	int Month;
	int Year;

	int Hour;
	int Minute;
};


class Ticket
{
private:
	string show_name;
	string venue_name;
	Date_Time when;
	Seat seat_id;
	bool sold;

public:
	Ticket(string Show_Name,
		string Venue_Name,
		Date_Time When,
		Seat Seat_ID);

	string Show_Name() const { return show_name; };
	string Venue_Name() const { return venue_name; };
	Date_Time When() const { return when; };
	Seat Seat_ID() const { return seat_id; };
	bool Sold() const { return sold; };

	void Sell() { sold = true; };
	void Display();
	~Ticket();
};




