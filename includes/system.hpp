#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "astronaut.hpp"
#include "flight.hpp"
#include <string>
#include <list>

bool register_astronaut(Astronaut obj, std::list<Astronaut> list);

bool register_flight(Flight obj, std::list<Flight> list);

bool add_asrtonaut_flight_by_cpf(std::string cpf, Flight flight);

bool remove_asrtonaut_flight_by_cpf(std::string cpf, Flight flight);

bool launch_flight(Flight flight);

bool boom_flight(Flight flight);

bool end_flight(Flight flight);

void list_flights(std::list<Flight> list);

void list_dead_astronauts(std::list<Astronaut> list);

#endif