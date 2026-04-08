/* Author: Lane Dorscher
 * Date: 04/06/2026
 * Program Name: M4-Disccussion-LaneDorscher.cpp
 * Program Description:
 * Program Assignment: Create a simple C++ program using repetition control statements and at least two errors. The program should not execute and there should be at least two errors in the code.
 * Modified by Daniel Preller
 * 04/06/2026
*/


//Daniel Preller: Added missing "include" keyword to include statements
#include <iostream>
#include <string>

using namespace std;

int main()
{

	int num;

	cout << "I am Count Dracula and I shall count to your number!\n";
	cout << "Enter a number and I will count to it! ";
	cin >> num;

	int counter;
	const string hahaMsg = "Ha Ha Ha!";

	//As a for loop
	cout << "\n\nI shall count forward! \n";//Daniel Preller: Corrected two single quotes to one double quote
		//Daniel Preller: I did not change this because it still works, but it would be more common to declare the counter variable within the for loop expression:
		//for (int counter = 1; counter <= num; counter++)
		for (counter = 1; counter <= num; counter++)
		{
			cout << counter;
			if (counter % 2 == 0)
				cout << "   (" + hahaMsg + ")";
			cout << endl;
		}

	//as a while loop
	counter = num;
	cout << "\n\nNow I shall count backwards!\n";
	while (counter > 0)
	{
		cout << counter;
		if (counter % 2 != 0)
			cout << "   (" + hahaMsg + ")";
		cout << endl;

		counter -- ;//Daniel Preller: Corrected subtraction operator(-) to decrement operator (--)
	}

	cout << "Bye bye! " << hahaMsg << endl;

	return 0;
}