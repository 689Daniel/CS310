/*
 * Student Name: Daniel Preller
 * File Name: Ch12Exercise03.cpp
 * Date: 5/20/2026
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Function prototypes
bool isAlphabeticString(string input);
string getCandidateName(int candidateNumber);
int getVotes(string candidate);
int getIntAboveMin(int min, const string& prompt = "  Please enter a positive integer: ", const string& errorMessage = "  ERROR: Please enter a positive integer: ");

int main() {
    cout << "\n\n";

    // Gets the number of candidates
    int numberOfCandidates = getIntAboveMin(1, "  Please enter the number of candidates: ",
        "  ERROR: Please try again. Enter a digit larger than zero: ");

    // Creates arrays to store candidates and votes
    // Technically, these could be regular arrays and not pointers,
    // but the assignment instructions and context suggest that pointers are expected
    string *candidateNames = new string[numberOfCandidates];
    int *candidateVotes = new int[numberOfCandidates];

    // Gets candidate names
    for (int i = 0; i < numberOfCandidates; i++) {
        candidateNames[i] = getCandidateName(i + 1);// Displayed numbers start from 1
    }

    // Gets the votes for each candidate
    for (int i = 0; i < numberOfCandidates; i++) {
        candidateVotes[i] = getVotes(candidateNames[i]);
    }

    // Calculates the total votes
    int totalVotes = 0;
    for (int i = 0; i < numberOfCandidates; i++) {
        totalVotes += candidateVotes[i];
    }

    // Prints header
    cout << "\n  " << setw(30) << left << "Candidate Name" << setw(12) << "Votes" << "Percentage of Total Votes" << endl;

    // Prints the information for each candidate
    for (int i = 0; i < numberOfCandidates; i++) {
        double votesPercentage = 100 * static_cast<double>(candidateVotes[i]) / totalVotes;// Percentage of total votes
        cout << "  " << setw(30) << candidateNames[i] << setw(12) << candidateVotes[i] << fixed << setprecision(3) << votesPercentage << endl;
    }

    // Determines and prints the winner
    int winner = 0;
    int mostVotes = 0;
    for (int i = 0; i < numberOfCandidates; i++) {
        if (candidateVotes[i] > mostVotes) {
            mostVotes = candidateVotes[i];
            winner = i;
        }
    }
    cout << "  The winner of the election is " << candidateNames[winner] << "." << endl;

    getch();// Holds for user input

    // Deallocates memory and closes program
    delete [] candidateNames;
    delete [] candidateVotes;
    return 0;
}

bool isAlphabeticString(string input) {// Returns true for alphabetic strings and false otherwise
    bool alphabetic = true;
    for (char c : input) {
        if (!isalpha(c)) {
            alphabetic = false;
        }
    }
    return alphabetic;
}

string getCandidateName(int candidateNumber) {// Gets a candidate's name, using a number in the prompt
    string name;
    cout << "  Enter the last name of candidate #" << candidateNumber << ": ";

    //Prints an error and repeats until an alphabetic string between 0 and 25 characters is entered
    while (!(cin >> name) || !isAlphabeticString(name) || name.empty() || name.length() > 25) {
        cout << "  ERROR: Please try again (names can be a maximum of 25 characters and must be alphabetical): ";
    }
    cin.ignore(INT_MAX, '\n');// Removes any input after whitespace
    return name;
}

int getVotes(string candidate) {// Gets the number of votes for a candidate, using the candidate's name in the prompt
    int votes;
    votes = getIntAboveMin(0, "  Enter the number of votes for " + candidate + ": ",
        "  ERROR: Please try again. Enter the number of votes as a positive digit: ");
    return votes;
}

// Gets an int above a specified minimum from the user, using a custom prompt and error message
int getIntAboveMin(int min, const string& prompt, const string& errorMessage) {
    cout << prompt;
    int number;
    while (!(cin >> number) || number < min) {// Repeatedly gets a value from the user until it is valid
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << errorMessage;
    }
    cin.ignore(INT_MAX, '\n');// Removes any extra input
    return number;
}