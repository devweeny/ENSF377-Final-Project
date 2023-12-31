#include "Airline.h"

int main() {
    Airline airline;
    Flight flight;
    std::string filename = "flight_info.txt";

    airline.display_header();
    airline.populate_flight_from_file(flight, filename);
    airline.menu(flight, filename);

    return 0;
}
