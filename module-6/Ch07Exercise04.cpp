/*
 * Student Name: Daniel Preller
 * File Name: Ch07Exercise04.cpp
 * Date: 4/20/2026
*/

#include <iostream>
#include <conio.h>

using namespace std;

bool isVowel(char character);
string removeVowels(string input);

int main() {//Gets a string as user input, removes vowels, and returns only the consonants
    string inputString;
    cout << "\n\n  Please enter a string (a sequence of characters): ";
    cin >> inputString;

    string outputString = removeVowels(inputString);
    cout << "  '" << inputString << "' without any vowels is '" << outputString << "'." << endl;
    getch();

}

bool isVowel(char character) {// Returns true if a character is a vowel and false otherwise
    switch (character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

string removeVowels(string operating_string) {// Removes vowels from a string
    for (int i = 0; i < operating_string.length();) {// Iterates through the string, but does not increase iterator automatically
        if (isVowel(operating_string[i])) {// If position is a vowel, removes it

            // Vowels are removed using the erase() method. The instructions call for the substr() method,
            // but erase() directly suits the problem and is generally a better choice
            operating_string.erase(i, 1);

        } else {// Otherwise, moves to next position
            i++;
        }
    }
    return operating_string;
}