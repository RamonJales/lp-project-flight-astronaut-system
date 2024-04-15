#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <list>
#include "astronaut.hpp"
#include "enums/FlightStateEnum.hpp"

class Flight {
private:
  int code;
  FlightStateEnum flightState;
  std::list<Astronaut> astronauts;

public:
  Flight();
  Flight(int code, FlightStateEnum flightState, std::list<Astronaut> astronauts);

  int getCode();
  FlightStateEnum getFlightState();
  std::list<Astronaut> getAstronauts();

  void setCode(int code);
  void setFlightState(FlightStateEnum flightState);
};

#endif