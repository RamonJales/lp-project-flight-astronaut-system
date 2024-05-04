#include <iostream>
#include "includes/astronaut.hpp"
#include "includes/flight.hpp"
#include "includes/interface.hpp"
#include "includes/system.hpp"
#include "includes/enums/AstronautStateEnum.hpp"
#include <list>


int main() {
    std::list<Flight> databaseFlight;
    std::list<Astronaut> databaseAstronaut;
    int flightId = 1;
    int astronautId = 1;

    print_menu();

    //tratar as exceções

    int option;
    do {
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option) {
            case 1:
            {
                Astronaut astronaut;
                std::string name;
                std::string cpf;
                int age;
                std::list<int> flightCodes;

                std::cout << "Enter astronaut name: ";
                std::cin >> name;

                std::cout << "Enter astronaut cpf: ";
                std::cin >> cpf;

                std::cout << "Enter astronaut age: ";
                std::cin >> age;

                astronaut = Astronaut(astronautId, cpf, name, age, true, ALIVE, flightCodes);
                register_astronaut(astronaut, databaseAstronaut);
                astronautId++;
                break;
            }
            case 2:
                {
                    Flight flight;
                    int code;
                    std::list<std::string> astronautsCpf;

                    std::cout << "Enter flight code: ";
                    std::cin >> code;

                    flight = Flight(flightId, code, PLANNING, astronautsCpf);
                    register_flight(flight, databaseFlight);
                    flightId++;
                    break;
                }
            case 3:
                // Code for option 3
                break;
            case 4:
                // Code for option 4
                break;
            case 5:
                // Code for option 5
                break;
            case 6:
                // Code for option 6
                break;
            case 7:
                // Code for option 7
                break;
            case 8:
                // Code for option 8
                break;
            case 9:
                // Code for option 9
                break;
            case 10:
            {
                list_astronauts(databaseAstronaut);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}