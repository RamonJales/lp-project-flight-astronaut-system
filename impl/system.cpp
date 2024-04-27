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

bool add_asrtonaut_to_flight_by_cpf(std::string cpf, Flight &flight) {
    if (flight.getFlightState() == PLANNING) {
        flight.getAstronautsCpf().push_back(cpf);
        return true;
    }
    return false;
}

bool remove_astronaut_from_flight_by_cpf(std::string cpf, Flight &flight) {
    if (flight.getFlightState() == PLANNING) {
        flight.getAstronautsCpf().remove(cpf);
        return true;
    }
    return false;
}

bool launch_flight(Flight &flight, std::list<Astronaut> &databaseAstronaut) {
    if (flight.getFlightState() == PLANNING && flight.getAstronautsCpf().size() > 0) {
        bool allAstronautsAvailable = true;
        for (auto& cpf : flight.getAstronautsCpf()) {
            Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
            if (astronaut->isAvailable() == true) {
                astronaut->setAvailable(false);
            }
        }
        flight.setFlightState(ONGOING);
        return true;
    }
    return false;
}

bool boom_flight(Flight &flight, std::list<Astronaut> &databaseAstronaut) {
    if (flight.getFlightState() == ONGOING) {
        for (auto& cpf : flight.getAstronautsCpf()) {
            Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
            astronaut->setAvailable(false);
            astronaut->setAstronautState(DEAD);
        }
        flight.setFlightState(PLANNING);
        return true;
    }
    return false;
}