#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <list>
#include "astronaut.hpp"

class Flight {
private:
  int code;
  std::list<Astronaut> astronauts;

public:
  Flight();
  Flight(int code, std::list<Astronaut> astronauts);

  int getCode();
  std::list<Astronaut> getAstronauts();

  void setCode(int code);
};

#endif