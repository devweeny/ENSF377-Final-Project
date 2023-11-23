#include "Airline.h"
using namespace std;

Airline::Airline() : airlineName(""), numOfFlights(0) {}

Airline::Airline(const string &name) : airlineName(name), numOfFlights(0) {}

Airline::Airline(const Airline &other) {
    this->airlineName = other.airlineName; 
    this->flights = other.flights;
    this->numOfFlights = other.numOfFlights;
} 

Airline::~Airline() {
    // Perform any necessary cleanup here
}

string Airline::getAirlineName() const {
    return airlineName;
}

void Airline::setAirlineName(const string &name) {
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
