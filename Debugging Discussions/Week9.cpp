/*
 * Student Name: Daniel Preller
 * File Name: Week9.cpp
 * Date: 5/12/2026
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Function prototypes for functions used within classes
string boolToString(bool value, string trueString, string falseString);
int getIntInRange(int min, int max);

// Stores name and price information for menu items
// Would be an abstract class, but those are not introduced until next week
class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem() {// Default constructor
        setName("Item");
        setPrice(0);
    }

    MenuItem(string name, double price) {
        setName(name);
        setPrice(price);
    }

    // Set methods
    void setName(string name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }
    // Get methods
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    // Prints the item as a line in a menu
    void printBasicMenuLine() {
        cout << setw(30) << left << name;
        cout << "$" << fixed << setprecision(2) << price << endl;
    }

    // Prints the item as a detailed line in a menu
    // Calls the basic version in the base class, but can be overridden for subclasses
    void printDetailedMenuLine() {
        printBasicMenuLine();
    }
};

// Represents a food item in a menu
class FoodItem {
private:
    bool glutenFree = false;

public:
    // Default constructor
    FoodItem(): MenuItem() {
        glutenFree = false;
    }

    // Constructor matching that of superclass
    FoodItem(string name, double price): MenuItem(name, price) {
        glutenFree = false;
    }

    // Constructor for all fields
    FoodItem(string name, double price, bool glutenFree): MenuItem(name, price) {
        this->glutenFree = glutenFree;
    }

    // Prints the detailed menu line, including whether the item is gluten-free
    void printDetailedMenuLine() {
        cout << setw(20) << left << name;
        cout << setw(15) << boolToString(glutenFree, "Yes", "No");
        cout << "$" << fixed << setprecision(2) << price << endl;
    }
};

// Represents a drink item in a menu
class DrinkItem: public MenuItem {
private:
    // Fields for prices of different sizes
    // The inherited price field is used for the 'regular' size
    double smallPrice;
    double largePrice;

public:
    // Default constructor
    DrinkItem(): DrinkItem("Item", 0) {}

    // Constructor matching that of parent class
    DrinkItem(string name, double price): MenuItem(name, price) {
        // Default prices for small and large are 50 cents above and below
        // regular price, respectively, but cannot be negative
        smallPrice = max(price - 0.50, 0.0);
        largePrice = price + 0.50;
    }

    // Constructor for all fields
    DrinkItem(string name, double price, double smallPrice, double largePrice) : MenuItem(name, price) {
        this->smallPrice = smallPrice;
        this->largePrice = largePrice;
    }

    // Prints a detailed menu line, including prices for all sizes
    void printDetailedMenuLine() {
        cout << setw(20) << left << name;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << smallPrice;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << price;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << largePrice << endl;
    }

    // Get methods
    double getSmallPrice() {
        return smallPrice;
    }

    double getLargePrice() {
        return largePrice;
    }
};

// Menu class is used to make a menu of items and to order from it
class Menu {
private:
    string name;
    FoodItem foodItems[3];// For this example, the number of food items is hardcoded to 3
    DrinkItem drinkItems[2];// For this example, the number of drink items is hardcoded to 2

public:

    // Constructor using a name
    Menu(string name) {
        this->setName(name);
    }

    // Name set method
    void setName(string name) {
        this->name = name;
    }

    // Sets specific items in the lists
    // Validation of a valid index is left to the calling function for this example
    void setFoodItem(int itemNumber, FoodItem item) {
        foodItems[itemNumber] = item;
    }

    void setDrinkItem(int itemNumber, DrinkItem item) {
        drinkItems[itemNumber] = item;
    }

    // Get methods
    string getName() {
        return name;
    }

    // Prints the menu information
    void printMenu() {
        // Header
        cout << "  " << name << " Menu:" << endl;
        cout << "    " << setw(30) << left << "Item" << "Price" << endl;

        int itemCounter = 1;// Used to display item numbers
        for (FoodItem item : foodItems) {// Displays all food items
            cout << "  " << itemCounter << " ";
            item.printBasicMenuLine();
            itemCounter++;
        }
        for (DrinkItem item : drinkItems) {// Displays all drink items
            cout << "  " << itemCounter << " ";
            item.printBasicMenuLine();
            itemCounter++;
        }
        cout << endl;
    }

    // Prints the drink menu with details on sizes
    void printDrinkMenu() {
        // Header
        cout << "  " << name << " Drink Menu:" << endl;
        cout << "    " << setw(20) << left << "Item" << setw(10) << "Small" << setw(10) << "Regular"
        << setw(10) << "Large" << endl;

        int itemCounter = 1;// Used for displaying the item number
        for (DrinkItem item : drinkItems) {// Displays all drink items
            cout << "  " << itemCounter << " ";
            item.printBasicMenuLine();
            itemCounter++;
        }
    }

    // Prints the food menu with details on whether items are gluten-free
    void printFoodMenu() {
        // Header
        cout << "  " << name << " Food Menu:" << endl;
        cout << "    " << setw(20) << left << "Item" << setw(15) << "Gluten-free" << setw(10) << "Price" << endl;

        int itemCounter = 1;// Used for displaying the item number
        for (FoodItem item : foodItems) {// Displays all food items
            cout << "  " << itemCounter << " ";
            item.printDetailedMenuLine();
            itemCounter++;
        }
    }

    // Takes an item number, a size (size only matters for drink items), and a total value
    // and adds the appropriate price to the total
    void orderItem(int itemNumber, int size, double& total) {
        string itemName;
        double itemPrice;
        string sizeName = "";// Used to display the size in the output

        itemNumber--;// Because user-facing item numbers are indexed from 1, decrements the item number
        if (itemNumber >= 0 && itemNumber <= 2) {// Gets the name and price of a food item
            itemName = foodItems[itemNumber].getName();
            itemPrice = foodItems[itemNumber].getPrice();
        } else if (itemNumber >= 3 && itemNumber <= 4) {// Gets the name and price of a drink item
            itemNumber = itemNumber - 3;// Adjusts the item number to be used on the drinks array
            itemName = drinkItems[itemNumber].getName();

            switch (size) {// Gets the price for the appropriate size, with regular as the default
                case 1:
                    itemPrice = drinkItems[itemNumber].getSmallPrice();
                    sizeName = "small ";
                default:
                case 2:
                    itemPrice = drinkItems[itemNumber].getPrice();
                    sizeName = "regular ";
                    break;
                case 3:
                    itemPrice = drinkItems[itemNumber].getLargePrice();
                    sizeName = "large ";
                    break;
            }
        } else {// Throws an error if an invalid value is passed
            throw invalid_argument("Invalid item number");
        }

        // Updates total and displays results
        total += itemPrice;
        cout << "\n  Added one " << sizeName << itemName << " to your order." << endl;
        cout << "  Your total is now $" << fixed << setprecision(2) << total << endl;
    }
};

// Function prototypes
void mainMenuLoop(Menu& menu, double& total);
void basicMenuLoop(Menu& menu, double& total);
void foodMenuLoop(Menu& menu, double& total);
void drinkMenuLoop(Menu& menu, double& total);

int main() {
    double total = 0.0;
    string cafeName;

    // Arrays used to create objects and populate menu
    string foodItems[3] = {"Bagel", "Muffin", "Parfait"};
    double foodPrices[3] = {3.00, 3.50, 4.00};
    bool foodGlutenFreeStatus[3] = {false, false, true};

    string drinkItems[2] = {"Coffee", "Tea"};
    double drinkPrices[2] = {3.75, 3.50};


    do {// Gets a cafe name from the user, ensuring it is not empty
        cout << "\n\n  Please enter a cafe name: ";
        getline(cin, cafeName);
    }
    while (cafeName.empty());

    Menu menu(cafeName);// Creates the menu

    // Populates menu with food and drink items
    for (int i = 0; i < 3; i++) {
        menu.setFoodItem(i, FoodItem(foodItems[i], foodPrices[i], foodGlutenFreeStatus[i]));
    }
    for (int i = 0; i < 2; i++) {
        menu.setDrinkItem(i, DrinkItem(drinkItems[i], drinkPrices[i]));
    }


    cout << "  Welcome to " << menu.getName() << "!" << endl;

    mainMenuLoop(menu, total);// Main execution loop
    getch();
    return 0;
}

// Main execution loop, which allows users to show other menus or complete an order
void mainMenuLoop(Menu& menu, double& total) {
    int selection;

    bool continuing = true;
    while (continuing) {// Displays instructions and gets the user's choice
        cout << "\n  Please enter a number to select an option:" << endl;
        cout << "  0 Complete order" << endl;
        cout << "  1 Display simple menu" << endl;
        cout << "  2 Display detailed food menu" << endl;
        cout << "  3 Display detailed drink menu" << endl;
        cout << "  ";
        selection = getIntInRange(0, 3);

        switch (selection) {// Processes user's choice
            case 0:// Prints closing message and ends program
                cout << "  Thank you for visiting " << menu.getName() << "! Your total is $" << fixed << setprecision(2) << total << endl;
                continuing = false;
                break;
            default:
            case 1:// Opens the basic menu
                basicMenuLoop(menu, total);
                break;
            case 2:// Opens the food menu
                foodMenuLoop(menu, total);
                break;
            case 3:// Opens the drink menu
                drinkMenuLoop(menu, total);
                break;
        }
    }
}

// Prints the menu and allows the user to order an item or go back
// As this is the basic menu, the drink size defaults to regular
void basicMenuLoop(Menu& menu, double& total) {
    while (true) {// Loops until user exits
        cout << endl;
        menu.printMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        // Gets the user's selection and directs execution accordingly
        int itemSelection = getIntInRange(0, 5);
        if (itemSelection == 0) {// Ends the loop if the sentinel is entered
            break;
        } else {// Orders an item
            menu.orderItem(itemSelection, 2, total);// Defaults to regular drink size if a drink is ordered
        }
    }
}

// Prints the food menu and allows the user to order an item or go back
void foodMenuLoop(Menu& menu, double& total) {
    while (true) {
        cout << endl;
        menu.printFoodMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        // Gets the user's selection and directs execution accordingly
        int itemSelection = getIntInRange(0, 3);
        if (itemSelection == 0) {// Ends the loop if the sentinel is entered
            break;
        } else {// Orders an item
            menu.orderItem(itemSelection, 2, total);// Any value can be used for size for a food item
        }
    }
}

// Prints the drink menu and allows the user to order an item or go back
void drinkMenuLoop(Menu& menu, double& total) {
    while (true) {
        cout << endl;
        menu.printDrinkMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        // Gets the user's selection and directs execution accordingly
        int itemSelection = getIntInRange(0, 2);
        if (itemSelection == 0) {// Ends the loop if the sentinel is entered
            break;
        } else {// Gets the user's size selection and then orders the item
            cout << "\n  Please select a size." << endl;
            cout << "  Enter 1 for small, 2 for regular, and 3 for large: ";
            int size = getIntInRange(1, 3);
            // 3 is added to the selection to account for the food items that are not displayed
            menu.orderItem(itemSelection + 3, size, total);
        }
    }
}

// Gets an int value in a specified  range from the user
int getIntInRange(int min, int max) {
    int userInput;

    // Executes until a valid integer is entered
    while (!(cin >> userInput) || userInput < min || userInput > max) {
        cout << "  Input error. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    cin.ignore(INT_MAX, '\n');// Clears the input stream of any excess data after a space
    return userInput;
}

// Returns a string depending on the value of a bool
string boolToString(bool value, string trueString, string falseString) {
    if (value) {
        return trueString;
    } else {
        return falseString;
    }
}