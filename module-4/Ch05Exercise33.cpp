/*
 * Student Name: Daniel Preller
 * File Name: Ch05Exercise33.cpp
 * Date: 4/7/2026
*/

#include  <conio.h>
#include <iostream>

using namespace std;

int main() {
    int base_time;
    int time_increment;
    int time_limit;

    cout << "Enter the time it takes to prepare the first dish: ";
    cin >> base_time;
    cout << "Enter the amount of extra time it takes to prepare each consecutive dish: ";
    cin >> time_increment;
    cout << "Enter the amount of time available to prepare all the dishes: ";
    cin >> time_limit;

    int total_time = 0;
    int dishes = 0;

    while (total_time <= time_limit) {//For each dish until the time exceeds the limit, adds time to prepare the dish
        total_time += base_time + time_increment * dishes;
        dishes++;
    }
    dishes--;//Loop calculates until the limit is exceeded, so 1 dish is removed from the count

    cout << "In " << time_limit << " minute" << (time_limit == 1 ? "" : "s") << ", Bianca can prepare " << dishes <<
        " dish" << (dishes == 1 ? "" : "es") << "." << endl;//Prints output with properly formatted plurals

    getch();
    return 0;
}