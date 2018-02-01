#include <fstream>
#include <iostream>
#include <string>
#include "Circle.h"

//Circle* Create_Circle()
//{
//	string name;
//	double radius;
//	cout << "Name? ";
//	getline(cin, name);
//	cout << "Radius? ";
//	cin >> radius;
//    cin.get();
//	return new Circle(name, radius);
//}

void Display_Circles(Circle** circles, int nr_circles)
{
    cout << endl;
    for (int i = 0; i < nr_circles; ++i)
    {
        circles[i]->Display();
    }
    cout << endl;
}


// Read circle data from a text file, set up Circle objects
// in caller's array, and return number of Circles.
// Negative count indicates error.
int Get_Circles(Circle** Circle_Array, int Max_Circles)
{
    int count = 0;
    ifstream infile;
    string name;
    double radius;
    infile.open("Circles.txt");

    if (!infile.is_open())
    {
        cout << "Failed to open file\n";
        return -1;	// Error
    }

    // Input file is open
    while ((count < Max_Circles) && infile.good())
    {
        string name;
        double radius;
        infile >> name;
        infile >> radius;

        if (!infile.good())
        {
            break;
        }
        //Circle c(name, radius);
        //Circle_Array[count++] = c;

        Circle_Array[count++] = new Circle(name, radius);

    }
    
    if (infile.eof())
    {
        cout << endl << "End of file \n";
    }
    else
    {
        cout << endl << "Error reading file\n";
        count = -1;
    }

    infile.close();
    return count;
}

void swap_circles(Circle*& c1, Circle*& c2)
{
    Circle* temp = c1;
    c1 = c2;
    c2 = temp;
}


void Sort_Circles(Circle** circles, int nr_circles)
{
    bool swap_done = false;
    do
    {
        swap_done = false;
        for (int i = 0; i < nr_circles - 1; ++i)
        {
            if (*circles[i] > *circles[i + 1])
            {
                swap_circles(circles[i], circles[i + 1]);
                swap_done = true;
            }
        }
    } while (swap_done);
}

int main()
{
    Circle* circles[20];
    cout << "This is Circle Sort\n";
    int count = -1;

    count = Get_Circles(circles, 20);
    if (count < 1)
    {
        cout << "Failed to read Circles file\n";
        cin.get();
        return -1;
    }

    cout << count << " Circles read\n";
    Display_Circles(circles, count);

    Sort_Circles(circles, count);

    cout << "Sorted circles:\n";
    Display_Circles(circles, count);



    cout << "Normal completion\n";
    cin.get();
}
