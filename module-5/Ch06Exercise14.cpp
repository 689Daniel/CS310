/*
 * Student Name: Daniel Preller
 * File Name: Ch06Exercise14.cpp
 * Date: 4/13/2026
*/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

//Function prototype
double calculateBill(double rate, int minutes, bool lowIncome);

int main() {
    double rate;
    int time;
    string lowIncomeString;
    bool lowIncome;

    //Gets user input
    cout << "\n\n  Please enter the hourly rate: ";
    cin >> rate;
    cout << "  Please enter the consulting time in minutes: ";
    cin >> time;
    cout << "  Does the client have low income? enter 'yes' or 'no' (case-sensitive): ";
    cin >> lowIncomeString;

    //Sets income status according to user input
    if (lowIncomeString == "yes") {
        lowIncome = true;
    } else if (lowIncomeString == "no") {
        lowIncome = false;
    } else {//Stops program if an invalid string is entered
        cout << "  Invalid input." << endl;
        return 1;
    }

    //Prints results and holds
    cout << fixed << setprecision(2) << "  The billing amount is " << calculateBill(rate, time, lowIncome) << "." << endl;
    getch();
    return 0;
}

//Calculates a client's bill based on hourly rate, consulting time, and income status
double calculateBill(double rate, int minutes, bool lowIncome) {
    int timeLimit = 20;
    double ratePercentage = 0.70; //Indicates what percentage of the rate is used because instructions never say the full rate is used

    if (lowIncome) {//Changes time limit and rate discount based on income status
        timeLimit = 30;
        ratePercentage = 0.40;
    }

    //Calculates bill
    if (minutes <= timeLimit) {
        return 0;
    } else {
        return ((double) (minutes - timeLimit) / 60) * rate * ratePercentage;
    }
}