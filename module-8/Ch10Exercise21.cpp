/*
 * Student Name: Daniel Preller
 * File Name: Ch10Exercise21.cpp
 * Date: 5/3/2026
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// BankAccount class is used to represent a bank account
// Class currently only includes variables and set/get methods
class BankAccount {
    private:
    string holderName = "John Doe";
    int accountNumber;
    string type = "checking";
    double balance = 0.0;
    double interestRate = 0.0;

    public:

    BankAccount() {// Default constructor uses default inizializations for all fields except account number
        setAccountNumber();
    }

    // Constructor sets all fields except account number with function input
    BankAccount(string holderName, int accountNumber, string type, double balance, double interestRate) {
        setHolderName(holderName);
        setType(type);
        setBalance(balance);
        setInterestRate(interestRate);
        setAccountNumber();
    }

    // Getter methods
    string getHolderName() {
        return holderName;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getType() {
        return type;
    }

    double getBalance() {
        return balance;
    }

    double getInterestRate() {
        return interestRate;
    }

    // Setter methods
    // Because exceptions have not yet been introduced in the class, invalid arguments only crash the program
    void setHolderName(string newHolderName) {
        if (newHolderName.empty()) {
            throw invalid_argument("Holder name cannot be empty.");
        } else {
            holderName = newHolderName;
        }
    }

    void setType(string newType) {
        if (newType != "checking" && newType != "savings") {
            throw invalid_argument("Type must be either 'checking' or 'savings'.");
        } else {
            type = newType;
        }
    }

    void setBalance(double newBalance) {
        if (newBalance < 0) {
            throw invalid_argument("Balance cannot be negative.");
        } else {
            balance = newBalance;
        }
    }

    void setInterestRate(double newInterestRate) {
        if (newInterestRate < 0) {
            throw invalid_argument("Interest rate cannot be negative.");
        } else {
            interestRate = newInterestRate;
        }
    }

    // Private set method for setting account number, ensuring unique values
    private:
    void setAccountNumber() {
        static int numberOfAccounts;
        accountNumber = ++numberOfAccounts;
    }
};

// Function prototype
void printAccount(BankAccount& account);

int main() {

    // Creates an array of 10 bank accounts and populates it
    BankAccount accountArray[10];
    string accountNames[10] = {"John Smith", "Jane Doe", "Steve Howard", "Anne Lane", "Jeremy Preston",
        "Susan Johnson", "Robert Lewis", "Melissa Douglas", "Patrick Hoffman", "Claire Weston"};
    string types[10] = {"checking", "savings", "savings", "savings", "checking", "checking",
        "savings", "checking", "savings", "savings"};
    double balances[10] = {13575.70, 12206.45, 10826.33, 14843.87, 19212.12, 27674.06, 21093.24, 18245.31, 25129.47, 28104.58};
    double interstRates[10] = {0.13, 0.20, 0.10, 0.30, 0.20, 0.14, 0.10, 0.10, 0.16, 0.23};
    for (int i = 0; i < 10; i++) {
        accountArray[i].setHolderName(accountNames[i]);
        accountArray[i].setType(types[i]);
        accountArray[i].setBalance(balances[i]);
        accountArray[i].setInterestRate(interstRates[i]);
    }

    // Prints all account information
    cout << "\n\n  Initial account information:" << endl;
    for (BankAccount i : accountArray) {
        printAccount(i);
    }

    // Transfers an amount from one account to another
    double transferAmount = 157.89;
    accountArray[0].setBalance(accountArray[0].getBalance() - transferAmount);
    accountArray[1].setBalance(accountArray[1].getBalance() + transferAmount);

    // Displays transfer results
    cout << "  After transferring money from John Smith to Jane Doe:" << endl;
    printAccount(accountArray[0]);
    printAccount(accountArray[1]);

    // Halts execution and ends program
    cout << "  Press 'enter' to close.";
    getch();
    return 0;
}

// Prints all the fields of an account
void printAccount(BankAccount& account) {
    cout << "  Account Holder: " << account.getHolderName() << endl;
    cout << "  Account Number: " << account.getAccountNumber() << endl;
    cout << "  Account Type: " << account.getType() << endl;
    cout << "  Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
    cout << "  Interest Rate: %" << account.getInterestRate() * 100 << endl;
    cout << endl;
}
