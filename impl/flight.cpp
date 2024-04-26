#include "../includes/flight.hpp"
#include "../includes/astronaut.hpp"
#include "../includes/enums/FlightStateEnum.hpp"

Flight::Flight(){};

Flight::Flight(int id, int code, FlightStateEnum flightState, std::list<std::string> astronautsCpf){
  this->id = id;
  this->code = code;
  this->flightState = flightState;
  this->astronautsCpf = astronautsCpf;
}

int Flight::getId() { return this->id; }
int Flight::getCode() { return this->code; }
FlightStateEnum Flight::getFlightState() { return this->flightState; } 
std::list<std::string> Flight::getAstronautsCpf() { return this->astronautsCpf; }

void Flight::setCode(int code) { this->code = code; }
void Flight::setFlightState(FlightStateEnum flightState) {this->flightState = flightState;}