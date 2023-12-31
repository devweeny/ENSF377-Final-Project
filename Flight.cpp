#include "Flight.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

void Flight::show_seat_map() {
    std::cout << "Seat Map for Flight " << flightNumber << ":" << std::endl;

    // Display column letters
    std::cout << "     ";
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
                if (row == i && j == seat - 'A') {
                    std::cout << "| X ";
                    isOccupied = true;
                    break;
                }
            }
            if (!isOccupied) {
                std::cout << "|   ";
            }
        }
        std::cout << "|" << std::endl << "   ";
        for (int j = 0; j < seatsPerRow; ++j) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
}


void Flight::show_passenger_info() {
    // iterate through passenger list and print with proper formatting
    std::cout << std::left << std::setw(20) << "| First Name"
        << std::left << std::setw(20) << "| Last Name"
        << std::left << std::setw(20) << "| Phone Number"
        << std::left << std::setw(8) << "| Seat"
        << std::left << std::setw(8) << "| ID" << "|" << std::endl;

    // Separator line bw table header and passenger info
    std::cout << std::setfill('-') << std::setw(76) << "|" << std::setfill(' ') << std::endl;

    for (size_t i = 0; i < passengerList.size(); ++i) {
        // Print data with vertical lines
        std::cout << std::left << std::setw(20) << "| " + passengerList[i].getFirstName()
            << std::left << std::setw(20) << "| " + passengerList[i].getLastName()
            << std::left << std::setw(20) << "| " + passengerList[i].getPhoneNumber()
            << std::left << std::setw(8) << "| " + std::to_string(passengerList[i].getAssignedSeat()->getRow()) + passengerList[i].getAssignedSeat()->getSeat()
            << std::left << std::setw(8) << "| " + std::to_string(passengerList[i].getIdNumber()) << "|" << std::endl;

        // Separator line after each row
        std::cout << std::setfill('-') << std::setw(76) << "|" << std::setfill(' ') << std::endl;
    }
    std::cout << std::endl;

}

void Flight::load_passenger_info(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.size() < 64) {
                continue;
            }
            // 0-19, 20-39, 40-59, 60-67, 68-75 of each line
            // std::istringstream iss(line);
            std::string firstName, lastName, phoneNumber, seat, idString;
            firstName = line.substr(0, 20);
            // trim whitespace off each string
            firstName.erase(firstName.find_last_not_of(" \n\r\t") + 1);
            lastName = line.substr(20, 20);
            lastName.erase(lastName.find_last_not_of(" \n\r\t") + 1);
            phoneNumber = line.substr(40, 20);
            phoneNumber.erase(phoneNumber.find_last_not_of(" \n\r\t") + 1);
            seat = line.substr(60, 4);
            seat.erase(seat.find_last_not_of(" \n\r\t") + 1);
            idString = line.substr(64, 8);
            idString.erase(idString.find_last_not_of(" \n\r\t") + 1);

            int idNumber = std::stoi(idString);
            int seatNumber = std::stoi(seat.substr(0, seat.size() - 1));
            char row = seat[seat.size() - 1];

            passengerList.push_back(Passenger(firstName, lastName, phoneNumber, new Seat(seatNumber, row), idNumber));
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Flight::add_passenger() {
    std::string firstName, lastName, phoneNumber;
    int idNumber;
    std::string seat_row;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Enter seat row and seat (Example: 1A): ";
    std::cin >> seat_row;
    int row = std::stoi(seat_row.substr(0, seat_row.size() - 1));
    char seat = seat_row[seat_row.size() - 1];
    std::cin.clear();
    std::cin.ignore(10000, '\n');
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


    Passenger newPassenger(firstName, lastName, phoneNumber, new Seat(row, seat), idNumber);
    passengerList.push_back(newPassenger);
    std::cout << "Passenger added to Flight " << flightNumber << "." << std::endl;

    save_passenger_info("flight_info.txt");
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
    char confirm;
	std::cout << "Do you want to save the data in " << filename << "file? (Y/N): ";
    std::cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << std::left << std::setw(9) << flightNumber << std::setw(6) << numRows << std::setw(6) << seatsPerRow << std::endl;

            for (const Passenger& passenger : passengerList) {
                Seat* assignedSeat = passenger.getAssignedSeat();
                file << std::left << std::setw(20) << passenger.getFirstName() << std::setw(20) << passenger.getLastName()
                    << std::setw(20) << passenger.getPhoneNumber() << std::setw(4) << std::to_string(assignedSeat->getRow()) + assignedSeat->getSeat()
                    << std::setw(8) << passenger.getIdNumber() << std::endl;
                // clear the buffer
                file.flush();
            }
            file.close();
            std::cout << "Passenger information saved to file." << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    } else {
        std::cout << "File not saved." << std::endl;
    }
}
