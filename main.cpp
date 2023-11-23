#include "seat.h"
#include <iostream>

using namespace std;

int menu() {
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
        return menu();
    }
    return choice;
}

void printStart() {
    cout << "Version 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced by: Dylan Wenaas, Aly Farouz, Wesley Lui" << endl;
}

void menuSelect() {
    while (true) {
        int choice;
        choice = menu();
        switch (choice)
        {
        case 1:
            // Print the seat map
            break;
        case 2:
            // Print the passenger information
            break;
        case 3:
            // Add a new passenger
            break;
        case 4:
            // Remove an existing passenger
            break;
        case 5:
            // Save data
            break;
        case 6:
            exit(1);
            break;

        default:
            break;
        }
    }

}


int main() {
    printStart();
    menuSelect();
    return 0;
}
