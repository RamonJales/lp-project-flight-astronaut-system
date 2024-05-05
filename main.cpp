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
                {
                    int flightCode;
                    std::string cpf;
                    Flight* flight;

                    std::cout << "Digite astronaut cpf: ";
                    std::cin >> cpf;

                    std::cout << "Digite o código do voo: ";
                    std::cin >> flightCode;

                    flight = findFlightByCode(flightCode, databaseFlight);

                    if (flight != nullptr) {
                        if (add_asrtonaut_to_flight_by_cpf(cpf, *flight)) {
                            std::cout << "Astronauta adicionado ao voo com sucesso." << std::endl;
                        } else {
                            std::cout << "Não foi possível adicionar o astronauta ao voo." << std::endl;
                        }
                    } else {
                        std::cout << "Voo não encontrado." << std::endl;
                    }
                    break;
                }
            case 4:
                {
                    int flightCode;
                    std::string cpf;
                    Flight* flight;

                    std::cout << "Digite astronaut cpf: ";
                    std::cin >> cpf;

                    std::cout << "Digite o código do voo: ";
                    std::cin >> flightCode;

                    flight = findFlightByCode(flightCode, databaseFlight);

                    if (flight != nullptr) {
                        if (remove_astronaut_from_flight_by_cpf(cpf, *flight)) {
                            std::cout << "Astronauta removido do voo com sucesso." << std::endl;
                        } else {
                            std::cout << "Não foi possível remover o astronauta do voo." << std::endl;
                        }
                    } else {
                        std::cout << "Voo não encontrado." << std::endl;
                    }
                    break;
                }
            case 5:
                {
                    int flightCode;
                    Flight* flight;

                    std::cout << "Digite o código do voo: ";
                    std::cin >> flightCode;

                    flight = findFlightByCode(flightCode, databaseFlight);

                    if (flight != nullptr) {
                        if (launch_flight(*flight, databaseAstronaut)) {
                            std::cout << "Voo lançado com sucesso." << std::endl;
                        } else {
                            std::cout << "Não foi possível lançar o voo." << std::endl;
                        }
                    } else {
                        std::cout << "Voo não encontrado." << std::endl;
                    }

                    break;
                }
            case 6:
                {
                    int flightCode;
                    Flight* flight;

                    std::cout << "Digite o código do voo: ";
                    std::cin >> flightCode;

                    flight = findFlightByCode(flightCode, databaseFlight);
                    
                    if (flight != nullptr) {
                        if (boom_flight(*flight, databaseAstronaut)) {
                            std::cout << "Voo explodido com sucesso." << std::endl;
                        } else {
                            std::cout << "Não foi possível explodir o voo." << std::endl;
                        }
                    } else {
                        std::cout << "Voo não encontrado." << std::endl;
                    }
                    break;
                }
            case 7:
                {
                    int flightCode;
                    Flight* flight;

                    std::cout << "Digite o código do voo: ";
                    std::cin >> flightCode;

                    flight = findFlightByCode(flightCode, databaseFlight);

                    if (flight != nullptr) {
                        if (finish_flight(*flight, databaseAstronaut)) {
                            std::cout << "Voo finalizado com sucesso." << std::endl;
                        } else {
                            std::cout << "Não foi possível finalizar o voo." << std::endl;
                        }
                    } else {
                        std::cout << "Voo não encontrado." << std::endl;
                    }
                    break;
                }
            case 8:
                {
                    list_flights(databaseFlight, databaseAstronaut);
                    break;
                }
            case 9:
                {
                    list_dead_astronauts(databaseAstronaut);
                    break;
                }
            case 10:
            {
                list_astronauts(databaseAstronaut);
                break;
            }
            default:
                std::cout << "Escolha inválida. Por favor, tente novamente." << std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}