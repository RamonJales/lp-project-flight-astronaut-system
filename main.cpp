#include <iostream>
#include "includes/astronaut.hpp"
#include "includes/flight.hpp"
#include "includes/interface.hpp"
#include <list>


int main() {
    std::list<Flight> databaseFlight;
    std::list<Astronaut> databaseAstronaut;

    print_menu();

    int option;
    do {
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option) {
            case 1:
                // Code for option 1
                break;
            case 2:
                // Code for option 2
                break;
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
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}