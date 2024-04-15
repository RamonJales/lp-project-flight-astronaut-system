#include "../includes/flight.hpp"
#include "../includes/astronaut.hpp"
#include "../includes/enums/FlightStateEnum.hpp"

Flight::Flight(){};

Flight::Flight(int code, FlightStateEnum flightState, std::list<Astronaut> astronauts) {
  this->code = code;
  this->flightState = flightState;
  this->astronauts = astronauts;
}

int Flight::getCode() { return this->code; }
FlightStateEnum Flight::getFlightState() { return this->flightState; } 
std::list<Astronaut> Flight::getAstronauts() { return this->astronauts; }

void Flight::setCode(int code) { this->code = code; }
void Flight::setFlightState(FlightStateEnum flightState) {this->flightState = flightState;}