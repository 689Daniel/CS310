/*
 * Student Name: Daniel Preller
 * File Name: Ch10Exercise21.cpp
 * Date: 5/13/2026
*/

#include <iomanip>
#include <iostream>

using namespace std;

// Represents a bank account
// This class is not used to create objects and would be an abstract class
// if that was not a topic for later weeks
class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Default constructor
    BankAccount() {
        accountNumber = 0;
        balance = 0.0;
    }

    // Constructor for all fields
    BankAccount(int accountNumber, double balance) {
        setAccountNumber(accountNumber);
        this->balance = balance;
    }

    // Set method for account number (balance is only set with transactions or constructor)
    void setAccountNumber(int accountNumber) {
        this->accountNumber = accountNumber;
    }

    // Get methods
    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    // Deposits a positive value into the account
    void deposit(double amount) {
        if (amount < 0) {
            throw invalid_argument("Amount must be positive");
        } else {
            balance += amount;
        }
    }

    // Withdraws a positive value from the account
    // Instead prints an error message if the balance would be negative
    void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Amount must be positive");
        } else if (amount > balance) {
            cout << "  Unable to perform withdrawal. Amount is larger than balance" << endl;
        } else {
            balance -= amount;
        }
    }

    // Prints account details
    void printAccount() {
        cout << "  Account Type: Standard" << endl;
        cout << "  Account Number: " << accountNumber << endl;
        cout << "  Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

// Represents a checking account
class CheckingAccount : public BankAccount {
protected:
    double interestRate;
    double minimumBalance;
    double serviceCharge;

public:
    // Default constructor
    CheckingAccount(): BankAccount() {
        interestRate = 0.0;
        minimumBalance = 0.0;
        serviceCharge = 0.0;
    }

    // Constructor for all fields
    CheckingAccount(int accountNumber, double balance, double interestRate, double minimumBalance, double serviceCharge): BankAccount(accountNumber, balance) {
        setInterestRate(interestRate);
        setMinimumBalance(minimumBalance);
        setServiceCharge(serviceCharge);
    }

    // Set methods
    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }

    void setMinimumBalance(double minimumBalance) {
        this->minimumBalance = minimumBalance;
    }

    void setServiceCharge(double serviceCharge) {
        this->serviceCharge = serviceCharge;
    }

    // Get methods
    double getInterestRate() {
        return interestRate;
    }

    double getMinimumBalance() {
        return minimumBalance;
    }

    double getServiceCharge() {
        return serviceCharge;
    }

    // Calculates interest based on the entire interest rate
    void postInterest() {
        balance = balance + balance * interestRate;
    }

    // Returns true if the balance is at or above the minimum and false otherwise
    bool verifyMinimumBalance() {
        return balance >= minimumBalance;
    }

    // Overridden method to withdraw a positive amount from the account
    // If the balance would be below the minimum, applies a service charge
    // Prints an error message instead if the balance would be negative
    // Different messages are given depending on whether the balance would be negative on its own
    // or because of the service charge
    void withdraw(double amount) {
        if (amount < 0) {// If amount is negative
            throw invalid_argument("Amount must be positive");
        } else if (amount > balance) {// If balance would be negative
            cout << "  Unable to perform withdraw. Amount is larger than balance" << endl;
        } else if (balance - amount > minimumBalance) {// If final balance would be above minimum
            balance -= amount;
        } else if (balance - amount - serviceCharge < 0) {// If service charge would make balance  negative
            cout << "  Unable to perform withdraw. Service charge will bring balance to negative" << endl;
        } else {// If a service charge must be applied
            balance = balance - amount - serviceCharge;
            cout << "  A service charge of " << serviceCharge << " has been applied" << endl;
        }
    }

    // Because the program does not have a true concept of a check due to only representing bank
    // accounts and not checks or time, the writeCheck() method behaves almost identically to the
    // withdraw() method but with different error messages
    void writeCheck(double amount) {
        if (amount < 0) {
            throw invalid_argument("Amount must be positive");
        } else if (amount > balance) {
            cout << "  Unable to write check. Amount is larger than balance" << endl;
        } else if (balance - amount > minimumBalance) {
            balance -= amount;
        } else if (balance - amount - serviceCharge < 0) {
            cout << "  Unable to write check. Service charge will bring balance to negative" << endl;
        } else {
            balance = balance - amount - serviceCharge;
            cout << "  A service charge of " << serviceCharge << " has been applied" << endl;
        }
    }

    void printAccount() {// Prints account information
        cout << "  Account Type: Checking" << endl;
        cout << "  Account Number: " << accountNumber << endl;
        cout << "  Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "  Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "  Minimum Balance: $" << fixed << setprecision(2) << minimumBalance << endl;
        cout << "  Service Charge Fee: $" << fixed << setprecision(2) << serviceCharge << endl;
    }
};

// Represents a savings account
class SavingsAccount : public BankAccount {
protected:
    double interestRate;

public:
    // Default constructor
    SavingsAccount(): BankAccount() {
        interestRate = 0.0;
    }

    // Constructor for all fields
    SavingsAccount(int accountNumber, double balance, double interestRate): BankAccount(accountNumber, balance) {
        setInterestRate(interestRate);
    }

    // Set method
    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }

    // Get method
    double getInterestRate() {
        return interestRate;
    }

    // Calculates interest
    // Interest is calculated identically to the checking account
    // class, but assignment instructions said that interest should be
    // a feature of the subclasses and not the superclass
    void postInterest() {
        balance = balance + balance * interestRate;
    }

    /* Instructions say to override the withdraw method. However,
     * the SavingsAccount class has no difference in how it should
     * withdraw compared to the BankAccount class, so I have not done so
    */

    // Prints account information
    void printAccount() {
        cout << "  Account Type: Savings" << endl;
        cout << "  Account Number: " << accountNumber << endl;
        cout << "  Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "  Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

int main() {// Test program to demonstrate the features of the account classes
    CheckingAccount testCheckingAccount1 = CheckingAccount();
    CheckingAccount testCheckingAccount2 = CheckingAccount(1, 500.00, 0.1, 100.00, 20.00);

    SavingsAccount testSavingsAccount1 = SavingsAccount();
    SavingsAccount testSavingsAccount2 = SavingsAccount(3, 1000.00, 0.12);

    cout << "  Checking Account 1" << endl;
    testCheckingAccount1.printAccount();
    cout << endl;

    cout << "  Checking Account 2" << endl;
    testCheckingAccount2.printAccount();
    cout << endl;

    cout << "  Savings Account 1" << endl;
    testSavingsAccount1.printAccount();
    cout << endl;

    cout << "  Savings Account 2" << endl;
    testSavingsAccount2.printAccount();
    cout << endl;

    cout << "  Checking Account 1 after update" << endl;
    testCheckingAccount1.deposit(300.00);
    testCheckingAccount1.setMinimumBalance(200.00);
    testCheckingAccount1.setInterestRate(0.13);
    testCheckingAccount1.setServiceCharge(20.00);
    testCheckingAccount1.setAccountNumber(4);
    testCheckingAccount1.printAccount();
    cout << endl;

    cout << "  Savings Account 1 after update" << endl;
    testSavingsAccount1.deposit(400.00);
    testSavingsAccount1.setInterestRate(0.11);
    testSavingsAccount1.setAccountNumber(2);
    testSavingsAccount1.printAccount();
    cout << endl;

    cout << "  Checking Account 2 after depositing $15.00" << endl;
    testCheckingAccount2.deposit(15.00);
    testCheckingAccount2.printAccount();
    cout << endl;

    cout << "  Savings Account 2 after withdrawing $30.00" << endl;
    testSavingsAccount2.withdraw(30.00);
    testSavingsAccount2.printAccount();
    cout << endl;

    cout << "  Failed withdrawal on savings account 1" << endl;
    testSavingsAccount1.withdraw(100000);
    cout << endl;

    cout << "  Checking Account 1 after interest" << endl;
    testCheckingAccount1.postInterest();
    testCheckingAccount1.printAccount();
    cout << endl;

    cout << "  Savings account 2 after interest" << endl;
    testSavingsAccount2.postInterest();
    testSavingsAccount2.printAccount();
    cout << endl;

    cout << "  Service fees on Checking Account 1" << endl;
    testCheckingAccount1.withdraw(140.00);
    testCheckingAccount1.printAccount();
    cout << endl;

    cout << "  Is Checking Account 1 above the minimum balance?" << endl;
    cout << (testCheckingAccount1.verifyMinimumBalance() ? "  Yes" : "  No") << endl;
    cout << endl;

    cout << "  Checking Account 2 after writing $15.00 check" << endl;
    testCheckingAccount2.writeCheck(15.00);
    testCheckingAccount2.printAccount();
    cout << endl;

    cout << "  Failed check because of minimum balance on Checking Account 2" << endl;
    testCheckingAccount2.writeCheck(490.00);
    testCheckingAccount2.printAccount();
    cout << endl;
}