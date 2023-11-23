
#ifndef SEAT_H
#define SEAT_H



#endif


class Seat
{
public:
  Seat();
  Seat(const Seat& source);
  ~Seat();
  int getRowNumber();
  char getColumn();
  bool getStatus();
  void setRowNumber(int rowNumber);
  void setColumn(char column);
  void setStatus(bool status);

private:
  int rowNumber;
  char column;
  bool status;
};
