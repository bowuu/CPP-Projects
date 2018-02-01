#include <iostream>
#include <string>
#include <iomanip>
#include "Ticket.h"

using namespace std;

string Get_String(string prompt)
{
	string input_line;
	cout << prompt;
	getline(cin, input_line);
	return input_line;
}


void Clear_Keyboard_Input_Buffer()
{
	while (cin.get() != '\n');
}


Ticket* Create_Ticket()
{
	string show_name;
	string venue_name;
	Date_Time when;
	Seat seat;

	cout << "Please enter parameters for ticket\n";
	show_name = Get_String("Show Name: ");
	venue_name = Get_String("Venue Name: ");

	cout << "Day: ";
	cin >> when.Day;
	Clear_Keyboard_Input_Buffer();

	cout << "Month: ";
	cin >> when.Month;
	Clear_Keyboard_Input_Buffer();

	cout << "Year: ";
	cin >> when.Year;
	Clear_Keyboard_Input_Buffer();

	cout << "Hour: ";
	cin >> when.Hour;
	Clear_Keyboard_Input_Buffer();

	cout << "Minute: ";
	cin >> when.Minute;
	Clear_Keyboard_Input_Buffer();

	seat.Row = Get_String("Seat row: ");
	cout << "Seat number: ";
	cin >> seat.Number;
	Clear_Keyboard_Input_Buffer();

	return new Ticket(show_name, venue_name, when, seat);
}

void Display_Ticket(Ticket* t)
{
	cout << setfill('0');
	cout << "Show_Name = " << t->Show_Name() << endl;
	cout << "Venue_Name = " << t->Venue_Name() << endl;
	cout << "Date = " << t->When().Month << "/" << t->When().Day
		<< "/" << t->When().Year << endl;

	cout << "Time = "
		<< setw(2) << t->When().Hour << ":"
		<< setw(2) << t->When().Minute << endl;

	cout << "Seat " << t->Seat_ID().Row << t->Seat_ID().Number << endl;

	if (t->Sold())
	{
		cout << "Sold\n";
	}
	else
	{
		cout << "Not sold\n";
	}
}

int main()
{
	std::cout << "This is program Test_Ticket\n";

	Ticket* ticket = Create_Ticket();
	cout << "\n\nInitial ticket:\n";
	ticket->Display();

	cout << "\nUsing accessor functions:\n";
	Display_Ticket(ticket);

	cout << "\nCalling Sell for ticket\n";
	ticket->Sell();

	cout << "\nAfter ticket sold:\n";
	ticket->Display();
	cout << "\n\n";

	delete ticket;
	ticket = 0;

	cin.get();
}
