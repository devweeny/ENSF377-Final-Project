#ifndef FLIGHT_H
#define FLIGHT_H

#include "AllClasses.h"
using namespace std;

class Flight {
private:
    string flightID;
    int numRows;
    int numColumns;
    vector<vector<bool>> seatMap; // Assuming seat map is a 2D vector of bool representing seat availability
    vector<Passenger> passengers;

public:
    // Constructors
    Flight();
    Flight(const string& id, int rows, int columns);
    Flight(const Flight& other);

    // Destructor
    ~Flight();

    // Getters and setters
    string getFlightID() const;
    void setFlightID(const string& id);

    int getNumRows() const;
    void setNumRows(int rows);

    int getNumColumns() const;
    void setNumColumns(int columns);

    // Other member functions
    // Implement getters and setters for seat map if required
    vector<vector<bool>> getSeatMap() const;
    void setSeatMap(const vector<vector<bool>>& map);

    vector<Passenger> getPassengers() const;
    void setPassengers(const vector<Passenger>& passengersList);

    void addPassenger(const string& firstName, const string& lastName, const string& phoneNo, int& passengerID, Seat* passengerSeat);
    void addPassenger(const string& firstName, const string& lastName, const string& phoneNo);
    void removePassenger(const string& firstName, const string& lastName);
    void displaySeatMap() const;
    void displayPassengersInformation() const;

    void readFlightDataFromFile(const string& filename) const;
    void writeFlightDataToFile(const string& filename) const;


};

#endif // FLIGHT_H
