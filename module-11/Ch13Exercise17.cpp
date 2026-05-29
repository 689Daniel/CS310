/*
 * Student Name: Daniel Preller
 * File Name: Ch13Exercise17.cpp
 * Date: 28 May 2026
*/

#include <iostream>
#include <random>
#include <conio.h>
#include <cctype>

using namespace std;

void printRandomNumbers(default_random_engine& engine, uniform_int_distribution<int>& distribution, int quantity);
bool getYesOrNo(string prompt, string errorMessage);

int main() {
    const int MIN = 10;
    const int MAX = 100;
    const int QUANTITY = 25;

    const string INPUT_PROMPT = "  Do you want to print another " + to_string(QUANTITY) + " numbers?\n" +
        "  Enter y for yes or n for no: ";
    const string ERROR_MESSAGE = "  Invalid input. Please try again: ";

    random_device seedGenerator;// Used to seed the random engine
    default_random_engine randomGenerator(seedGenerator());// Random engine for generating numbers
    uniform_int_distribution<int> distribution(MIN, MAX);// Generates random integers in the specified range

    // Prints random numbers until the user stops the program
    cout << endl << endl;
    do {
        printRandomNumbers(randomGenerator, distribution, QUANTITY);
    } while (getYesOrNo(INPUT_PROMPT, ERROR_MESSAGE));
}

// Generates and prints a specified number of random numbers
void printRandomNumbers(default_random_engine& engine,uniform_int_distribution<int>& distribution, int quantity) {
    for (int i = 1; i <= quantity; i++) {
        cout << "  " << distribution(engine) << endl;
    }
}

// Gets a yes or no input from the user, formatted as y or n
bool getYesOrNo(string prompt, string errorMessage) {
    cout << prompt;
    string input;
    while (true) {// Repeats until a valid value is entered
        try {
            cin >> input;
            if (input == "y" || input == "Y") {
                cin.ignore(INT_MAX, '\n');
                return true;
            } else if (input == "n" || input == "N") {
                cin.ignore(INT_MAX, '\n');
                return false;
            } else {
                throw runtime_error("Invalid input value");
            }
        } catch (runtime_error& error) {// Clears and resets the input stream if an invalid value is entered
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << errorMessage;// Displays the error message
        }
    }
}