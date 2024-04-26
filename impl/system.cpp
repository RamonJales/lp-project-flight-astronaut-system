#include <iostream>
#include "../includes/system.hpp"
#include "../includes/enums/FlightStateEnum.hpp"

Astronaut* findAstronautById(int id, std::list<Astronaut> databaseAstronaut) {
    for (auto& astronaut : databaseAstronaut) {
      if (astronaut.getId() == id) {
        return &astronaut;
      }
    }
    return nullptr;
}

Flight* findFlightById(int id, std::list<Flight> databaseFlight) {
    for (auto& flight : databaseFlight) {
      if (flight.getId() == id) {
        return &flight;
      }
    }
    return nullptr;
}

Astronaut* findAstronautByCpf(std::string cpf, std::list<Astronaut> databaseAstronaut) {
    for (auto& astronaut : databaseAstronaut) {
      if (astronaut.getCpf() == cpf) {
        return &astronaut;
      }
    }
    return nullptr;
}

void register_astronaut(Astronaut obj, std::list<Astronaut> &databaseAstronaut) {
    databaseAstronaut.push_back(obj);
}

void register_flight(Flight obj, std::list<Flight> &databaseFlight) {
    databaseFlight.push_back(obj);
}

bool add_asrtonaut_to_flight_by_cpf(std::string cpf, Flight flight) {
    if (flight.getFlightState() == PLANNED) {
        flight.getAstronautsCpf().push_back(cpf);
    }
}

