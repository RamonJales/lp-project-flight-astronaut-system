#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "astronaut.hpp"
#include "flight.hpp"
#include <string>
#include <list>

Astronaut* findAstronautById(int id, std::list<Astronaut> databaseAstronaut);

Flight* findFlightById(int id, std::list<Flight> databaseFlight);

Astronaut* findAstronautByCpf(std::string cpf, std::list<Astronaut> databaseAstronaut);

void register_astronaut(Astronaut obj, std::list<Astronaut> &databaseAstronaut);

void register_flight(Flight obj, std::list<Flight> &databaseFlight);

bool add_asrtonaut_to_flight_by_cpf(std::string cpf, Flight &flight);

bool remove_astronaut_from_flight_by_cpf(std::string cpf, Flight &flight);

bool launch_flight(Flight &flight, std::list<Astronaut> &databaseAstronaut);

bool boom_flight(Flight &flight, std::list<Astronaut> &databaseAstronaut);

bool finish_Flight(Flight &flight, std::list<Astronaut> &databaseAstronaut);

void list_flights(std::list<Flight> databaseFlight, std::list<Astronaut> databaseAstronaut);

void list_dead_astronauts(std::list<Astronaut> list);

void sort_flights_by_state(std::list<Flight>& flights);

#endif