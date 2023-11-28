#ifndef PMAIN_H
#define PMAIN_H

//GLOBAL FUNCTIONS
int menu();
void print_start();
void menuSelect(Flight& flight);
readFlightDataFromFile(const string& filename) const ;

//SWITCH MENU FUNCTIONS
//OPTION 1
void displaySeatMap();
//OPTION 2
void displayPassengersInformation();
//OPTION 3
void addPassenger(firstName, lastName, phoneNo,passengerID,passengerSeat);
//OPTION 4
void removePassenger(firstName, lastName);
//OPTION 5
void saveFlightDataToFile(filename);

#endif