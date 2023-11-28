#include <iostream>
#include "Flight.h"
#include "AllClasses.h"
using namespace std;

Flight::Flight() : flightID(""), numRows(0), numColumns(0) {
    // Initialize seat map and other members as needed
}

Flight::Flight(const std::string& id, int rows, int columns)
    : flightID(id), numRows(rows), numColumns(columns) {
    // Initialize seat map and other members as needed based on rows and columns
    seatMap.resize(numRows, std::vector<bool>(numColumns, false)); // Initializing seat map with rows and columns
}

Flight::Flight(const Flight& other) {
    this->flightID = other.flightID;
    this->numRows = other.numRows;
    this->numColumns = other.numColumns;
    this->seatMap = other.seatMap;
    this->passengers = other.passengers;
}

Flight::~Flight() {
    // Perform any necessary cleanup here
}

// Getters and setters implementations
std::string Flight::getFlightID() const {
    return flightID;
}

void Flight::setFlightID(const std::string& id) {
    flightID = id;
}

int Flight::getNumRows() const {
    return numRows;
}

void Flight::setNumRows(int rows) {
    numRows = rows;
}

int Flight::getNumColumns() const {
    return numColumns;
}

void Flight::setNumColumns(int columns) {
    numColumns = columns;
}

std::vector<std::vector<bool>> Flight::getSeatMap() const {
    return seatMap;
}

void Flight::setSeatMap(const std::vector<std::vector<bool>>& map) {
    seatMap = map;
}

std::vector<std::string> Flight::getPassengers() const {
    if (passengers.empty()) {
        cout << "No passengers to display." << endl;
        return;
    }

    cout << "Passenger Information:" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "First Name | Last Name | Phone Number | Row | Column | Passenger ID" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    for (const Passenger& passenger : passengers) {
        //const prevents modification while allowing the reference of other passengers
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
    
    return passengers;
}

void Flight::setPassengers(const std::vector<std::string>& passengersList) {
    passengers = passengersList;
}
