//PASSENGER CPP FILE
#include "Passenger.h"
#include "seat.h"
using namespace std;

//Default Constructor
Passenger::Passenger() : firstName(""), lastName(""), phoneNo(""), passengerID(0), passengerSeat(nullptr) {}

//Constructor with Parameters
Passenger::Passenger(const std::string& fName, const std::string& lName, const std::string& pNo, int pID, Seat* pSeat)
    : firstName(fName), lastName(lName), phoneNo(pNo), passengerID(pID), passengerSeat(pSeat) {}

//Destructor
Passenger::~Passenger() {
    // Perform necessary cleanup
    // Delete passengerSeat if needed
}

//Getters
string Passenger::getFirstName() const { return firstName; }
string Passenger::getLastName() const { return lastName; }
string Passenger::getPhoneNo() const { return phoneNo; }
int Passenger::getPassengerID() const { return passengerID; }
Seat* Passenger::getPassengerSeat() const { return passengerSeat; }

//Setters
void Passenger::setFirstName(const string& fName) { firstName = fName; }
void Passenger::setLastName(const string& lName) { lastName = lName; }
void Passenger::setPhoneNo(const string& pNo) { phoneNo = pNo; }
void Passenger::setPassengerID(int pID) { passengerID = pID; }
void Passenger::setPassengerSeat(Seat* pSeat) { passengerSeat = pSeat; }
