#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>
#include "Flight.h"

class Airline {
private:
    std::string airlineName;
    std::vector<Flight> flights;
    int numOfFlights;

public:
    Airline();
    Airline(const std::string &name);
    Airline(const Airline &other);
    ~Airline();
    
    std::string getAirlineName() const;
    void setAirlineName(const std::string &name);
    int getNumOfFlights() const;
    void setNumOfFlights(int num);
    void addFlight(const Flight &newFlight);
};

#endif // AIRLINE_H
