#ifndef PASSENGER_H
#define PASSENGER_H

#include "Seat.h"
#include <string>

class Passenger {
public:
    Passenger(const std::string& first, const std::string& last, const std::string& phone, Seat* seat, int id);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    Seat* getAssignedSeat() const;
    int getIdNumber() const;

private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    Seat* assignedSeat;
    int idNumber;
};

#endif /* PASSENGER_H */
