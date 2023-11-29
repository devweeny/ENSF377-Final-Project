#include "Airline.h"
#include <iostream>
#include <fstream>

void Airline::display_header() {
    std::cout << "Welcome to the Airline Management System!" << std::endl;
    // Display any other information or headers here
}

void Airline::populate_flight_from_file(Flight& flight, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> flight.flightNumber >> flight.numRows >> flight.seatsPerRow;

        // Read passenger information
        std::string firstName, lastName, phoneNumber, seat;
        int idNumber;
        while (file >> firstName >> lastName >> phoneNumber >> seat >> idNumber) {
            int row = std::stoi(seat.substr(0, seat.length() - 1));
            char seatChar = seat[seat.length() - 1];
            Seat passengerSeat(row, seatChar);
            Passenger passenger(firstName, lastName, phoneNumber, &passengerSeat, idNumber);
            flight.passengerList.push_back(passenger);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Airline::menu(Flight& flight, const std::string& filename) {
    int choice;
    do {
        std::cout << "Menu:\n1. Show Seat Map\n2. Show Passenger Information\n3. Add Passenger\n4. Remove Passenger\n5. Save Passenger Information\n6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            flight.show_seat_map();
            break;
        case 2:
            flight.show_passenger_info(filename);
            break;
        case 3:
            flight.add_passenger();
            break;
        case 4:
            flight.remove_passenger();
            break;
        case 5:
            flight.save_passenger_info(filename);
            break;
        case 6:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 6);
}
