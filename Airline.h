#ifndef AIRLINE_H
#define AIRLINE_H
using namespace std;

#include "AllClasses.h"

class Airline {
private:
    string airlineName;
    vector<Flight> flights;
    int numOfFlights;

public:
    Airline();
    Airline(const string& name);
    Airline(const Airline& other);
    ~Airline();

    string getAirlineName() const;
    void setAirlineName(const string& name);
    int getNumOfFlights() const;
    void setNumOfFlights(int num);
    void addFlight(const Flight& newFlight);
};

#endif // AIRLINE_H
