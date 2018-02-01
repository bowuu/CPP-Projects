#include <iostream>
#include <cstring>
#include <iomanip>
#include "Ticket.h"

using namespace std;

Ticket::Ticket(string show_name_,
	string venue_name_,
	Date_Time when_,
	Seat seat_id_)
{
	show_name = show_name_;
	venue_name = venue_name_;
	when = when_;
	seat_id = seat_id_;
	sold = false;
}

void Ticket::Display()
{
	cout << setfill('0');
	cout << "Show_Name = " << show_name << endl;
	cout << "Venue_Name = " << venue_name << endl;
	cout << "Date = " << when.Month << "/" << when.Day
		<< "/" << when.Year << endl;

	cout << "Time = "
		 << setw(2) << when.Hour << ":"
		 << setw(2) << when.Minute << endl;

	cout << "Seat " << seat_id.Row << seat_id.Number << endl;

	if (sold)
	{
		cout << "Sold\n";
	}
	else
	{
		cout << "Not sold\n";
	}
}


Ticket::~Ticket(void)
{
}


