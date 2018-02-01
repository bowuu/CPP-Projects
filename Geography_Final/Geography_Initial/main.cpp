#include <iostream>
#include <string>
#include "tinyxml.h"
#include "City.h"
#include "State.h"
#include "menu.h"
#include "Command_Processor.h"
using namespace std;

void Get_Cities(TiXmlNode* capital_node, State* state)
{
    TiXmlNode* city_node = capital_node->NextSibling();
    while (city_node != 0)
    {
        string city_name = city_node->FirstChild()->Value();
        City c(city_name);
        state->Add_City(c);
        city_node = city_node->NextSibling();
    }
}

int Get_Data(State** states)
{
    int count = 0;
    string filename = "states.xml";
    TiXmlDocument doc(filename);
    bool loadOkay = doc.LoadFile();
    if (!loadOkay)
    {
        cout << "Could not load file " << filename << endl;
        cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
        cin.get();
        exit( 1 );
    }

    TiXmlNode* usa_node = doc.FirstChild("USA");
    assert(usa_node != 0);

    TiXmlNode* state_node = usa_node->FirstChild();
    while (state_node != 0)
    {
        TiXmlNode* name_node = state_node->FirstChild();
        string state_name = name_node->FirstChild()->Value();
        TiXmlNode* capital_node = name_node->NextSibling();
        City c(capital_node->FirstChild()->Value());
        State* state = new State(state_name, c);
        Get_Cities(capital_node, state);
        states[count++] = state;
        state_node = state_node->NextSibling();
    }
    return count;
}


void Display_Data(State** states, int nr_states)
{
    for (int i = 0; i < nr_states; ++i)
    {
        states[i]->Display();
    }
}

int main()
{
    State* states[50];
    int nr_states = 0;

    cout << "This is the Geography program\n\n";
    nr_states = Get_Data(states);

    Display_Data(states, nr_states);

    Command_Processor::Process_Commands(states, &nr_states);

    cout << "\nNormal Termination\n";
    cin.get();
    return 0;
}

//int main()
//{
//    Menu* menu = new Menu("Enter command number");
//    menu->Add_Command("Select State");
//    menu->Add_Command("Add State");
//    menu->Add_Command("Quit");
//
//    while (true)
//    {
//        const string* cmd = menu->Get_Command();
//        cout << "\nCommand was " << *cmd << endl << endl;
//        if (*cmd == "Quit")
//        {
//            break;
//        }
//    }
//    cout << "Normal termination\n";
//    cin.get();
//    cin.get();
//}


//int main(void)
//{
//    Command_Processor::Process_Commands();
//
//    cout << "Normal Termination\n";
//    cin.get();
//    cin.get();
//    return 0;
//}
