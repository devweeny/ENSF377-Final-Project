
#ifndef SEAT_H
#define SEAT_H


class Seat
{
public:
  Seat() { rowNumber = 0; column = 'A'; status = false; }
  Seat(const Seat& source);
  ~Seat();
  int getRowNumber() { return rowNumber; };
  char getColumn() { return column; }
  bool getStatus() { return status; }
  void setRowNumber(int row) { rowNumber = row; }
  void setColumn(char col) { column = col; }
  void setStatus(bool stat) { status = stat; }

private:
  int rowNumber;
  char column;
  bool status;
};

#endif