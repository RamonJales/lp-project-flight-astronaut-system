#include <iostream>
#include "includes/astronaut.hpp"
#include "includes/flight.hpp"
#include <list>


int main() {

    Astronaut obj("ramon", "s11414551", 45);

    std::list<Astronaut> list;

    list.push_back(obj);

    Flight flight1(1, list);

    std::cout << "hello";

    return 0;
}