#include "../includes/flight.hpp"
#include "../includes/astronaut.hpp"

Flight::Flight(){};

Flight::Flight(int code, std::list<Astronaut> astronauts) {
  this->code = code;
  this->astronauts = astronauts;
}

int Flight::getCode() { return this->code; }
std::list<Astronaut> Flight::getAstronauts() { return this->astronauts; }

void Flight::setCode(int code) { this->code = code; }