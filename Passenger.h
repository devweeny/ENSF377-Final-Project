//PASSENGER HEADER FILE     
#ifndef Passenger_h
#define Passenger_h
using namespace std;

class Passenger {
private:
    string firstName;
    string lastName;
    string phoneNo;
    int passengerID;
    Seat* passengerSeat;
public:
    //Constructors
    Passenger() : firstName(""), lastName(""), phoneNo(""), passengerID(0), passengerSeat(nullptr) {};

    Passenger(const std::string& fName, const std::string& lName, const std::string& pNo, int pID, Seat* pSeat)
        : firstName(fName), lastName(lName), phoneNo(pNo), passengerID(pID), passengerSeat(pSeat) {};

    //Copy Constructor
    Passenger(const Passenger& source);

    // Destructor
    ~Passenger();

    // Getters
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getPhoneNo() const { return phoneNo; }
    int getPassengerID() const { return passengerID; }
    Seat* getPassengerSeat() const { return passengerSeat; }

    // Setters
    void setFirstName(const string& fName) { firstName = fName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setPhoneNo(const string& pNo) { phoneNo = pNo; }
    void setPassengerID(int pID) { passengerID = pID; }
    void setPassengerSeat(Seat* pSeat) { passengerSeat = pSeat; }
};
#endif //Passenger.h File