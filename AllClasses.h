#ifndef ALLCLASSES_H
#define ALLCLASSES_H

#include <iostream>
#include <string>
#include <vector>


class Seat;


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

#endif // ALLCLASSES_H