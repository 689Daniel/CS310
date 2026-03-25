/*
 *Student Name: Daniel Preller
 *File Name: Ch03Exercise07.cpp
 *Date: 3/25/2026
*/

#include <iomanip>
#include <iostream>

using namespace std;

#include <conio.h>

int main() {
    double netBalance;
    double payment;
    int cycleDays;
    int daysBeforeCycle;
    double interestRate;


    //Sets the locale to the default, which will produce a thousands separator on some systems
    locale loc("");
    cout.imbue(loc);

    //Gets user input and assigns it to appropriate variables
    cout << fixed << setprecision(2) << "\n\n  Please enter the net balance: ";
    cin >> netBalance;
    cout << "\n  Please enter the payment amount: ";
    cin >> payment;
    cout << "\n  Please enter the number of days in the billing cycle: ";
    cin >> cycleDays;
    cout << "\n  Please enter the number of days the payment is made before the billing cycle: ";
    cin >> daysBeforeCycle;
    cout << "\n  Please enter the monthly interest rate: ";
    cin >> interestRate;

    //Calculates the interest
    double averageDailyBalance = (netBalance * cycleDays - payment * daysBeforeCycle) / cycleDays;
    double interestAmount = averageDailyBalance * interestRate;

    //Displays output
    cout << "\n  The total interest amount is " << interestAmount << endl;
    getch();//Holds program to view results
}