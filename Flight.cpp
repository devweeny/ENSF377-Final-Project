#include "AllClasses.h"

Flight::Flight() : flightID(""), numRows(0), numColumns(0) {
    // Initialize seat map and other members as needed
}

Flight::Flight(const string& id, int rows, int columns)
    : flightID(id), numRows(rows), numColumns(columns) {
    // Initialize seat map and other members as needed based on rows and columns
    seatMap.resize(numRows, vector<bool>(numColumns, false)); // Initializing seat map with rows and columns
}

Flight::Flight(const Flight& other) {
    flightID = other.flightID;
    numRows = other.numRows;
    numColumns = other.numColumns;
    seatMap = other.seatMap;
    passengers = other.passengers;
}

// Getters and setters implementations
string Flight::getFlightID() const {
    return flightID;
}

void Flight::setFlightID(const string& id) {
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

vector<vector<bool>> Flight::getSeatMap() const {
    return seatMap;
}

void Flight::setSeatMap(const vector<vector<bool>>& map) {
    seatMap = map;
}

vector<Passenger> Flight::getPassengers() const {
    return passengers;
}

void Flight::setPassengers(const vector<Passenger>& passengersList) {
    passengers = passengersList;
}

void Flight::displaySeatMap() const {
    vector<vector<bool>> seatMap = getSeatMap();


    for (const auto& row : seatMap) {
        for (bool status : row) {
            if (status) {
                cout << "O ";
            }
            else {
                cout << "A ";
            }
        }
        cout << endl;
    }
}
void Flight::displayPassengersInformation() const {
    for (const auto& passenger : passengers) {
        cout << "Name: " << passenger.getFirstName() << " " << passenger.getLastName() << endl;
        cout << "Phone No: " << passenger.getPhoneNo() << endl;
        cout << endl;
    }
}

void Flight::addPassenger(const string& firstName, const string& lastName, const string& phoneNo, int& passengerID, Seat* passengerSeat) {
    Passenger newPassenger(firstName, lastName, phoneNo, passengerID, passengerSeat);
    passengers.push_back(newPassenger);
}
void Flight::addPassenger(const string& firstName, const string& lastName, const string& phoneNo) {
    Passenger newPassenger(firstName, lastName, phoneNo, 10001234, nullptr);
    passengers.push_back(newPassenger);
}

void Flight::removePassenger(const string& firstName, const string& lastName) {
    for (auto it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->getFirstName() == firstName && it->getLastName() == lastName) {
            passengers.erase(it);
            cout << "Passenger removed successfully." << endl;
            return;
        }
    }
    cout << "Passenger not found." << endl;
}

void Flight::writeFlightDataToFile(const string& filename) const {
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