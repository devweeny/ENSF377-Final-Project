#include "Flight.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

void Flight::show_seat_map() {
    std::cout << "Seat Map for Flight " << flightNumber << ":" << std::endl;

    // Display column letters
    std::cout << "      ";
    for (int i = 0; i < seatsPerRow; ++i) {
        std::cout << static_cast<char>('A' + i) << "   ";
    }
    std::cout << std::endl;

    // Display seat map with borders and occupied seats
    for (int i = 1; i <= numRows; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < seatsPerRow; ++j) {
            bool isOccupied = false;
            for (size_t k = 0; k < passengerList.size(); ++k) {
                int row = passengerList[k].getAssignedSeat()->getRow();
                char seat = passengerList[k].getAssignedSeat()->getSeat();
                if (row == i && seat == static_cast<char>('A' + j)) {
                    std::cout << "| X ";
                    isOccupied = true;
                    break;
                }
            }
            if (!isOccupied) {
                std::cout << "| O ";
            }
        }
        std::cout << "|" << std::endl << "   ";
        for (int j = 0; j < seatsPerRow; ++j) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
}









void Flight::show_passenger_info(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string flightInfo;
        if (std::getline(file, flightInfo)) {
            std::cout << "Flight Information:" << std::endl;
            std::cout << flightInfo << std::endl;
        } else {
            std::cerr << "Empty file or missing flight information." << std::endl;
            return;
        }

        // Print header
        std::cout << std::left << std::setw(20) << "| First Name"
                  << std::left << std::setw(20) << "| Last Name"
                  << std::left << std::setw(20) << "| Phone Number"
                  << std::left << std::setw(8) << "| Seat"
                  << std::left << std::setw(8) << "| ID" << "|" << std::endl;

        // Separator line
        std::cout << std::setfill('-') << std::setw(76) << "|" << std::setfill(' ') << std::endl;

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string firstName, lastName, phoneNumber, seat, idString;

            iss >> std::setw(20) >> firstName
                >> std::setw(20) >> lastName
                >> std::setw(20) >> phoneNumber
                >> std::setw(8) >> seat
                >> std::setw(8) >> idString;

            int idNumber = std::stoi(idString);

            // Print data with vertical lines
            std::cout << std::left << std::setw(20) << "| " + firstName
                      << std::left << std::setw(20) << "| " + lastName
                      << std::left << std::setw(20) << "| " + phoneNumber
                      << std::left << std::setw(8) << "| " + seat
                      << std::left << std::setw(8) << "| " + std::to_string(idNumber) << "|" << std::endl;

            // Separator line after each row
            std::cout << std::setfill('-') << std::setw(76) << "|" << std::setfill(' ') << std::endl;
        }
        std::cout << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Flight::add_passenger() {
    std::string firstName, lastName, phoneNumber;
    int idNumber;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter seat row (number): ";
    int row;
    std::cin >> row;
    std::cout << "Enter seat (character): ";
    char seat;
    std::cin >> seat;
    std::cout << "Enter ID number: ";
    std::cin >> idNumber;

    bool seatOccupied = false;
    for (size_t i = 0; i < passengerList.size(); ++i) {
        if (passengerList[i].getAssignedSeat()->getRow() == row && passengerList[i].getAssignedSeat()->getSeat() == seat) {
            seatOccupied = true;
            break;
        }
    }

    if (row > numRows || row <= 0 || seat < 'A' || seat >= 'A' + seatsPerRow || seatOccupied) {
        std::cout << "Invalid seat selection or seat already occupied. Passenger not added." << std::endl;
        return;
    }

    Seat newSeat(row, seat);
    Passenger newPassenger(firstName, lastName, phoneNumber, &newSeat, idNumber);
    passengerList.push_back(newPassenger);
    std::cout << "Passenger added to Flight " << flightNumber << "." << std::endl;
}


void Flight::remove_passenger() {
    int id;
    std::cout << "Enter passenger ID to remove: ";
    std::cin >> id;

    for (std::vector<Passenger>::iterator it = passengerList.begin(); it != passengerList.end(); ++it) {
        if (it->getIdNumber() == id) {
            passengerList.erase(it);
            std::cout << "Passenger with ID " << id << " removed from Flight " << flightNumber << "." << std::endl;
            return;
        }
    }
    std::cout << "Passenger with ID " << id << " not found in Flight " << flightNumber << "." << std::endl;
}

void Flight::save_passenger_info(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << flightNumber << " " << numRows << " " << seatsPerRow << std::endl;

        for (std::vector<Passenger>::const_iterator it = passengerList.begin(); it != passengerList.end(); ++it) {
            file << it->getFirstName() << " " << it->getLastName() << " "
                 << it->getPhoneNumber() << " " << it->getAssignedSeat()->getRow()
                 << it->getAssignedSeat()->getSeat() << " " << it->getIdNumber() << std::endl;
        }
        file.close();
        std::cout << "Passenger information saved to file." << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
