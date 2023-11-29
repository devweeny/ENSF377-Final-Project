#ifndef FLIGHT_H
#define FLIGHT_H

#include "Passenger.h"
#include <vector>
#include <string>
class Flight {
public:
    std::string flightNumber;
    int numRows;
    int seatsPerRow;
    std::vector<Passenger> passengerList;

    void show_seat_map();
    void show_passenger_info(const std::string& filename);
    void add_passenger();
    void remove_passenger();
    void save_passenger_info(const std::string& filename);
};

#endif /* FLIGHT_H */

