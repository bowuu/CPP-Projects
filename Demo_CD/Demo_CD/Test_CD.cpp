#include <iostream>
#include "CD.h"
#include "CD_Info.h"

using namespace std;

int main()
{
	cout << "My CDs:\n";

	//CD* cd1 = new CD("Faking It", "12345", "George Fake", "Some Mfgr",
	//	2016, DDD);

	//Track* track1 = new Track("A Fake Track", 130, "Fake Artist",
	//	Pop);
	//cd1->Add_Track(track1);
	//cd1->Display();
	
	CD* my_cds[100];
	int nr_cds = 0;
	nr_cds = get_CDs(my_cds, 100);

	cin.get();
}