#ifndef SEAT_H
#define SEAT_H

class Seat {
public:
    Seat(int r, char s);

    int getRow() const { return row; }
    char getSeat() const { return seat; }

private:
    int row;
    char seat;
};

#endif /* SEAT_H */
