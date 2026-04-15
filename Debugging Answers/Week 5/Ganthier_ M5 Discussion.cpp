/*
 * Modified by Daniel Preller
 * 4/15/2026
*/

#include <iostream>
using namespace std;

// Daniel Preller: Added prototype for calculateArea() function
double calculateArea(double l, double w);

int main() {
    double length = 5.5;
    double width = 3.0;

    // Call the user-defined function
    double totalArea = calculateArea(length, width);

    cout << "The area of the rectangle is: " << totalArea << endl;

    return 0;
}

// User-defined function definition
double calculateArea(double l, double w) {// Daniel Preller: Changed function return type from void to double
    double area = l * w;
    return area;
}