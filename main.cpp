#include "seat.h"
#include <iostream>

using namespace std;

int printMenu() {
    cout << "1. Display Flight Seat Map." << endl;
    cout << "2. Display Passengers Information." << endl;
    cout << "3. Add a New Passenger." << endl;
    cout << "4. Remove an Existing Passenger." << endl;
    cout << "5. Save data." << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5, or 6)";
    int choice;
    cin >> choice;
    cin.clear();
    cin.ignore(10000, '\n');

    if (choice < 1 || choice > 6) {
        cout << endl << "Invalid choice. Please try again." << endl;
        return printMenu();
    }
    return choice;
}


int main() {
    int choice;
    choice = printMenu();

    cout << "You chose " << choice << endl;
    return 0;
}
