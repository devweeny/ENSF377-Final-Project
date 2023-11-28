#include "AllClasses.h"
#include "Pmain.h"
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

void menuSelect(Flight& flight) {
    while (true) {
        int choice;
        choice = menu();
        switch (choice)
        {
        case 1:
            displaySeatMap(Flight& flight);
            break;
        case 2:
            displayPassengersInformation();
            break;
        case 3:
            std::string firstName, lastName, phoneNo;
            int passengerID; // Initialize passengerID
            Seat* passengerSeat = nullptr;
            std::cout << "Enter passenger's first name: ";
            std::cin >> firstName;
            std::cout << "Enter passenger's last name: ";
            std::cin >> lastName;
            std::cout << "Enter passenger's phone number: ";
            std::cin >> phoneNo;
            flight.addPassenger(firstName, lastName, phoneNo,passengerID,passengerSeat);
            break;
        case 4:
            std::string firstName, lastName;
            std::cout << "Enter passenger's first name: ";
            std::cin >> firstName;
            std::cout << "Enter passenger's last name: ";
            flight.removePassenger(firstName, lastName);
            break;
        case 5:
            std::string filename = "flight_data.txt";
            flight.saveFlightDataToFile(filename);
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
    Flight flight;
    flight.readFlightDataFromFile("flight_info.txt");
    printStart();
    menuSelect(flight);
    return 0;
}

void displaySeatMap(Flight& flight){
    
}

void displayPassengersInformation(Flight& flight){
    //TODO: formatting columns for printing the table of info
    
    if (passengers.empty()) {
        cout << "No passengers to display." << endl;
        return;
    }

    cout << "Passenger Information:" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "First Name | Last Name | Phone Number | Row | Seat | ID" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    for (const Passenger& passenger : passengers) {
        //TODO: not sure how to loop through all our passengers to print all their info[]
        cout << passenger.getFirstName() << " | "
             << passenger.getLastName() << " | "
             << passenger.getPhoneNo() << " | ";

        Seat* passengerSeat = passenger.getPassengerSeat();
        if (passengerSeat) {
            cout << passengerSeat->getRowNumber() << " | "
                 << passengerSeat->getColumn() << " | ";
        } else {
            cout << "N/A | N/A | ";
        }

        cout << passenger.getPassengerID() << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void addPassenger(firstName, lastName, phoneNo,passengerID,passengerSeat){

}

void removePassenger(firstName, lastName){
    
}

void saveFlightDataToFile(const string& filename) const {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << flightID << "\n";
        outFile << numRows << "\n";
        outFile << numColumns << "\n";
        for (const auto& row : seatMap) {
            for (const char& seat : row) {
                outFile << seat << " ";
            }
            outFile << "\n";
        }
        for (const Passenger& passenger : getPassengers()) {
            outFile << passenger.getFirstName() << "\n";
            outFile << passenger.getLastName() << "\n";
            outFile << passenger.getPhoneNo() << "\n\n";
        }

        outFile.close();
        cout << "Flight data saved to " << filename << " successfully." << endl;
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}