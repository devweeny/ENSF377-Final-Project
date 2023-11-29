#include "Passenger.h"

// Constructor definition
Passenger::Passenger(const std::string& first, const std::string& last, const std::string& phone, Seat* seat, int id)
    : firstName(first), lastName(last), phoneNumber(phone), assignedSeat(seat), idNumber(id) {}

// Getter methods
std::string Passenger::getFirstName() const {
    return firstName;
}

std::string Passenger::getLastName() const {
    return lastName;
}

std::string Passenger::getPhoneNumber() const {
    return phoneNumber;
}

Seat* Passenger::getAssignedSeat() const {
    return assignedSeat;
}

int Passenger::getIdNumber() const {
    return idNumber;
}

