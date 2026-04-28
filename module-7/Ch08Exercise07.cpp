/*
 * Student Name: Daniel Preller
 * File Name: Ch08Exercise07.cpp
 * Date: 4/28/2026
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Function prototypes
bool isAlphabeticString(string input);
string getCandidateName(int candidateNumber);
int getVotes(string candidate);

int main() {
    cout << "\n\n";

    // Initializes arrays for candidate information
    int numberOfCandidates = 5;
    string candidateNames[numberOfCandidates];
    int candidateVotes[numberOfCandidates];

    // Gets candidate names
    for (int i = 0; i < numberOfCandidates; i++) {
        candidateNames[i] = getCandidateName(i + 1);
    }

    // Gets the votes for each candidate
    for (int i = 0; i < numberOfCandidates; i++) {
        candidateVotes[i] = getVotes(candidateNames[i]);
    }

    // Calculates the total votes
    int totalVotes = 0;
    for (int i : candidateVotes) {
        totalVotes += i;
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

    //Prints an error and repeats until a alphabetic string between 0 and 25 characters is entered
    while (!(cin >> name) || !isAlphabeticString(name) || name.empty() || name.length() > 25) {
        cout << "  ERROR: Please try again (names can be a maximum of 25 characters and must be alphabetical): ";
    }
    cin.ignore(INT_MAX, '\n');// Removes any output after whitespace
    return name;
}

int getVotes(string candidate) {// Gets the number of votes for a candidate, using the candidate's name in the prompt
    int votes;
    cout << "  Enter the number of votes for " << candidate << ": ";
    while (!(cin >> votes) || votes < 0) {// Repeats until a valid positive integer is entered
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "  ERROR: Please try again. Enter the number of votes as a digit: ";
    }
    cin.ignore(INT_MAX, '\n');// Removes any output after whitespace
    return votes;
}