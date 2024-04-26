#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <list>
#include "astronaut.hpp"
#include "enums/FlightStateEnum.hpp"

class Flight {
private:
  int id;
  int code;
  FlightStateEnum flightState;
  std::list<std::string> astronautsCpf;

public:
  Flight();
  Flight(int id, int code, FlightStateEnum flightState, std::list<std::string> astronautsCpf);

  int getId();
  int getCode();
  FlightStateEnum getFlightState();
  std::list<std::string> getAstronautsCpf();

  void setCode(int code);
  void setFlightState(FlightStateEnum flightState);
};

#endif