#include <iostream>
#include <string>
#include <vector>

class Seat {
public:
    Seat() : rowNumber(0), column('A'), status(false) {}
    Seat(const Seat& source);
    ~Seat();
    int getRowNumber() const { return rowNumber; }
    char getColumn() const { return column; }
    bool getStatus() const { return status; }
    void setRowNumber(int row) { rowNumber = row; }
    void setColumn(char col) { column = col; }
    void setStatus(bool stat) { status = stat; }

private:
    int rowNumber;
    char column;
    bool status;
};

Seat::Seat(const Seat& source) {
    this->rowNumber = source.rowNumber;
    this->column = source.column;
    this->status = source.status;
}

Seat::~Seat() {
    // Perform necessary cleanup
}

class Flight {
private:
    std::string flightID;
    int numRows;
    int numColumns;
    std::vector<std::vector<bool>> seatMap;
    std::vector<std::string> passengers;

public:
    Flight();
    Flight(const std::string& id, int rows, int columns);
    Flight(const Flight& other);
    ~Flight();
    std::string getFlightID() const;
    void setFlightID(const std::string& id);
    int getNumRows() const;
    void setNumRows(int rows);
    int getNumColumns() const;
    void setNumColumns(int columns);
    std::vector<std::vector<bool>> getSeatMap() const;
    void setSeatMap(const std::vector<std::vector<bool>>& map);
    std::vector<std::string> getPassengers() const;
    void setPassengers(const std::vector<std::string>& passengersList);
};

Flight::Flight() : flightID(""), numRows(0), numColumns(0) {}

Flight::Flight(const std::string& id, int rows, int columns)
    : flightID(id), numRows(rows), numColumns(columns) {
    seatMap.resize(numRows, std::vector<bool>(numColumns, false));
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
    return passengers;
}

void Flight::setPassengers(const std::vector<std::string>& passengersList) {
    passengers = passengersList;
}

class Passenger {
public:
    Passenger() : firstName(""), lastName(""), phoneNo(""), passengerID(0), passengerSeat(nullptr) {}
    Passenger(const std::string& fName, const std::string& lName, const std::string& pNo, int pID, Seat* pSeat);
    Passenger(const Passenger& source);
    ~Passenger();
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNo() const;
    int getPassengerID() const;
    Seat* getPassengerSeat() const { return passengerSeat; }
    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setPhoneNo(const std::string& pNo) { phoneNo = pNo; }
    void setPassengerID(int pID) { passengerID = pID; }
    void setPassengerSeat(Seat* pSeat) { passengerSeat = pSeat; }

private:
    std::string firstName;
    std::string lastName;
    std::string phoneNo;
    int passengerID;
    Seat* passengerSeat;
};

Passenger::Passenger(const std::string& fName, const std::string& lName, const std::string& pNo, int pID, Seat* pSeat)
    : firstName(fName), lastName(lName), phoneNo(pNo), passengerID(pID), passengerSeat(pSeat) {}

Passenger::Passenger(const Passenger& source) {
    this->firstName = source.firstName;
    this->lastName = source.lastName;
}
class Airline {
private:
    std::string airlineName;
    std::vector<Flight> flights;
    int numOfFlights;

public:
    Airline();
    Airline(const std::string& name);
    Airline(const Airline& other);
    ~Airline();
    std::string getAirlineName() const;
    void setAirlineName(const std::string& name);
    int getNumOfFlights() const;
    void setNumOfFlights(int num);
    void addFlight(const Flight& newFlight);
};


Airline::Airline() : airlineName(""), numOfFlights(0) {}

Airline::Airline(const std::string& name) : airlineName(name), numOfFlights(0) {}

Airline::Airline(const Airline& other) {
    this->airlineName = other.airlineName; 
    this->flights = other.flights;
    this->numOfFlights = other.numOfFlights;
} 

Airline::~Airline() {
    // Perform any necessary cleanup here
}

std::string Airline::getAirlineName() const {
    return airlineName;
}

void Airline::setAirlineName(const std::string& name) {
    airlineName = name;
}

int Airline::getNumOfFlights() const {
    return numOfFlights;
} 

void Airline::setNumOfFlights(int num) {
    numOfFlights = num;
}

void Airline::addFlight(const Flight& newFlight) {
    flights.push_back(newFlight);
    numOfFlights++;
}