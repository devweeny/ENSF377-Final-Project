#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

class Flight {
private:
    std::string flightID;
    int numRows;
    int numColumns;
    std::vector<std::vector<bool>> seatMap; // Assuming seat map is a 2D vector of bool representing seat availability
    std::vector<std::string> passengers;

public:
    // Constructors
    Flight();
    Flight(const std::string& id, int rows, int columns);
    Flight(const Flight& other);

    // Destructor
    ~Flight();

    // Getters and setters
    std::string getFlightID() const;
    void setFlightID(const std::string& id);

    int getNumRows() const;
    void setNumRows(int rows);

    int getNumColumns() const;
    void setNumColumns(int columns);

    // Other member functions
    // Implement getters and setters for seat map if required
    std::vector<std::vector<bool>> getSeatMap() const;
    void setSeatMap(const std::vector<std::vector<bool>>& map);

    std::vector<std::string> getPassengers() const;
    void setPassengers(const std::vector<std::string>& passengersList);
};

#endif // FLIGHT_H
