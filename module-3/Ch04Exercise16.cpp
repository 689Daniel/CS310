/*
 * Student Name: Daniel Preller
 * File Name: Ch04Exercise16.cpp
 * Date: 3/31/2026
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
    //Initializes constants and variables
    const double DELIVERY_AMOUNT = 5000;
    const double PUBLISHING_AMOUNT = 20000;

    const double OPTION_2_ROYALTY_RATE = 0.125;

    const double OPTION_3_BASE_ROYALTY_RATE = 0.10;
    const double OPTION_3_BONUS_ROYALTY_RATE = 0.14;
    const int OPTION_3_ROYALTY_THRESHOLD = 4000;

    int amountSold;
    double netPrice;

    double option1Total, option2Total, option3Total;

    string bestOption;

    cout << setprecision (2) << fixed;//Sets output to 2-decimal precision fixed output

    //Gets user input
    cout << "\n\n  Please enter the number of copies sold: " << endl;
    cin >> amountSold;
    cout << "  Please enter the net price: " << endl;
    cin >> netPrice;

    //Calculates totals for options 1 and 2
    option1Total = DELIVERY_AMOUNT + PUBLISHING_AMOUNT;
    option2Total = netPrice * amountSold * OPTION_2_ROYALTY_RATE;

    if (amountSold > OPTION_3_ROYALTY_THRESHOLD) {//Calculates total for option 3 with regular or bonus rate
        option3Total = (netPrice * OPTION_3_ROYALTY_THRESHOLD * OPTION_3_BASE_ROYALTY_RATE);
        option3Total += (netPrice * (amountSold - OPTION_3_ROYALTY_THRESHOLD) * OPTION_3_BONUS_ROYALTY_RATE);
    } else {
        option3Total = netPrice * amountSold * OPTION_3_BONUS_ROYALTY_RATE;
    }

    if (option1Total > option2Total) {//Determines the best option
        bestOption = "option 1";
    } else if (option2Total > option3Total) {
        bestOption = "option 2";
    } else {
        bestOption = "option 3";
    }

    //Outputs results
    cout << "  Option 1 will pay $" << DELIVERY_AMOUNT << " on delivery plus $" << PUBLISHING_AMOUNT <<
        " upon publishing for a total of $" << option1Total << endl;
    cout << "  Option 2 will pay " << OPTION_2_ROYALTY_RATE * 100 << "% of sales, for a total of $" << option2Total << endl;
    cout <<"   3 will pay " << OPTION_3_BASE_ROYALTY_RATE * 100 << "% of sales for the first " <<
        OPTION_3_ROYALTY_THRESHOLD << " sales plus " << OPTION_3_BONUS_ROYALTY_RATE * 100 <<
        "% for all remaining sales, for a total of $" << option3Total << endl;
    cout << "  The best option is " << bestOption << "." << endl;

    getch();
}