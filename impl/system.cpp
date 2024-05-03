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
        flight.setFlightState(EXPLODED);
        return true;
    }
    return false;
}

bool finish_Flight(Flight &flight, std::list<Astronaut> &databaseAstronaut) {
    if (flight.getFlightState() == ONGOING) {
        for (auto& cpf : flight.getAstronautsCpf()) {
            Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
            if (astronaut->getAstronautState() == ALIVE && astronaut->isAvailable() == false) {
                astronaut->setAvailable(true);
            }
        }
        flight.setFlightState(FINESHED);
        return true;
    }
    return false;
}

void list_dead_astronauts(std::list<Astronaut> databaseAstronaut) {
    for (auto& astronaut : databaseAstronaut) {
        if (astronaut.getAstronautState() == DEAD) {
            std::cout << "CPF: " << astronaut.getCpf() << std::endl;
            std::cout << "Name: " << astronaut.getName() << std::endl;
            std::cout << "Flights code participated: ";
            for (int flightCode : astronaut.getFlightCodes()) {
                std::cout << flightCode << "; ";
            }
            std::cout << "." << std::endl;
        }
    }
}

void sort_flights_by_state(std::list<Flight>& flights) {
    flights.sort([](Flight& a, Flight& b) {
        return a.getFlightState() < b.getFlightState();
    });
}

void list_flights(std::list<Flight> databaseFlight, std::list<Astronaut> databaseAstronaut) {
    int countPlanning, countOngoing, countExploded, countFinished = 0;
    sort_flights_by_state(databaseFlight);

    for (auto& flight : databaseFlight) {
        if(flight.getFlightState() == PLANNING) {
            if (countPlanning == 0) {
                std::cout << "- PLANNING:" << std::endl;
                std::cout << "Flight code: " << flight.getCode() << std::endl;
                countPlanning++;
            }
            else {
                std::cout << "Flight code: " << flight.getId() << std::endl;
            }
            std::cout << "- Flight astronauts:" << std::endl;
            for (auto& cpf : flight.getAstronautsCpf()) {
                Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
                std::cout << "Astronaut: " << astronaut->getName() << std::endl;
            }
        }
        else if(flight.getFlightState() == ONGOING) {
            if (countOngoing == 0) {
                std::cout << "- ONGOING:" << std::endl;
                std::cout << "Flight code: " << flight.getCode() << std::endl;
                countOngoing++;
            }
            else {
                std::cout << "Flight code: " << flight.getId() << std::endl;
            }
            std::cout << "- Flight astronauts:" << std::endl;
            for (auto& cpf : flight.getAstronautsCpf()) {
                Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
                std::cout << "Astronaut: " << astronaut->getName() << std::endl;
            }
        }
        else if(flight.getFlightState() == EXPLODED) {
            if (countExploded == 0) {
                std::cout << "- EXPLODED:" << std::endl;
                std::cout << "Flight code: " << flight.getCode() << std::endl;
                countExploded++;
            }
            else {
                std::cout << "Flight code: " << flight.getId() << std::endl;
            }
            std::cout << "- Flight astronauts:" << std::endl;
            for (auto& cpf : flight.getAstronautsCpf()) {
                Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
                std::cout << "Astronaut: " << astronaut->getName() << std::endl;
            }
        }
        else if(flight.getFlightState() == FINESHED) {
            if (countFinished == 0) {
                std::cout << "- FINISHED:" << std::endl;
                std::cout << "Flight code: " << flight.getCode() << std::endl;
                countFinished++;
            }
            else {
                std::cout << "Flight code: " << flight.getId() << std::endl;
            }
            std::cout << "- Flight astronauts:" << std::endl;
            for (auto& cpf : flight.getAstronautsCpf()) {
                Astronaut* astronaut = findAstronautByCpf(cpf, databaseAstronaut);
                std::cout << "Astronaut: " << astronaut->getName() << std::endl;
            }
        }
    }
}

void list_astronauts(std::list<Astronaut> databaseAstronaut) {
    for (auto& astronaut : databaseAstronaut) {
        std::cout << "Name: " << astronaut.getName() << std::endl;
        std::cout << "Astronaut state: " << astronaut.getAstronautState() << std::endl;
        std::cout << "Available: " << astronaut.isAvailable() << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }
}