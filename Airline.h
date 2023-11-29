#ifndef AIRLINE_H
#define AIRLINE_H

#include "Flight.h"

class Airline {
public:
    void display_header();
    void populate_flight_from_file(Flight& flight, const std::string& filename);
    void menu(Flight& flight, const std::string& filename);
};

#endif /* AIRLINE_H */

