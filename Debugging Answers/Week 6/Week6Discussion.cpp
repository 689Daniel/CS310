/*
 * Modified by Daniel Preller
 * 4/26/2026
*/

#include <iostream>
using namespace std;


enum TrafficLight { Red, Yellow, Green };// Daniel Preller: Corrected 'enumerate' keyword to 'enum'

int main()// Daniel Preller: Removed colon used to start function definition (brackets were already in place)
{
    int choice;
    TrafficLight light;

    cout << "Traffic Light Input Program" << endl;
    cout << "Enter a number for the light:" << endl;
    cout << "0 = Red" << endl;
    cout << "1 = Yellow" << endl;
    cout << "2 = Green" << endl;
    cin >> choice;

    
    light = static_cast<TrafficLight>(choice);

   // Daniel Preller: Added missing 'if' keyword to else...if statements
    if (light == Red)
        cout << "Stop!" << endl;
    else  if (light == Yellow)
        cout << "Slow down!" << endl;
    else  if (light == Green)
        cout << "Go!" << endl;
    else
        cout << "Invalid input." << endl;

    return 0;
}