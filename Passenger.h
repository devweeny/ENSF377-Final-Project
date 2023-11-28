//PASSENGER HEADER FILE
#include <iostream>
#include <string>
#include "seat.h"
using namespace std;

#ifndef Passenger_h
#define Passenger_h

class Passenger{
    public:
        //Constructors
        Passenger() : firstName(""), lastName(""), phoneNo(""), passengerID(0), passengerSeat(nullptr);

        Passenger(const std::string& fName, const std::string& lName, const std::string& pNo, int pID, Seat* pSeat)
            : firstName(fName), lastName(lName), phoneNo(pNo), passengerID(pID), passengerSeat(pSeat);
        
        //Copy Constructor
        Passenger(const Passenger& source);

        // Destructor
        ~Passenger();

        // Getters
        string getFirstName() const;
        string getLastName() const;
        string getPhoneNo() const;
        int getPassengerID() const;
        Seat* getPassengerSeat() const { return passengerSeat; }

        // Setters
        void setFirstName(const string& fName) { firstName = fName; }
        void setLastName(const string& lName) { lastName = lName; }
        void setPhoneNo(const string& pNo) { phoneNo = pNo; }
        void setPassengerID(int pID) { passengerID = pID; }
        void setPassengerSeat(Seat* pSeat) { passengerSeat = pSeat; }
    
    private:
        string firstName;
        string lastName;
        string phoneNo;
        int passengerID;
        Seat* passengerSeat;
};
#endif //Passenger.h File