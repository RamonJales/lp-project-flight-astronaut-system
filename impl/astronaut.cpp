#include "../includes/astronaut.hpp"

Astronaut::Astronaut() {}

Astronaut::Astronaut(int id, std::string cpf, std::string name, int age, bool available) {
  this->id = id;
  this->name = name;
  this->cpf = cpf;
  this->age = age;
  this->available = available;
}

int Astronaut::getId() { return this->id; }
std::string Astronaut::getName() { return this->name; }
std::string Astronaut::getCpf() { return this->cpf; }
int Astronaut::getAge() { return this->age; }
bool Astronaut::isAvailable() { return this->available; }

void Astronaut::setName(std::string name) { this->name = name; }
void Astronaut::setCpf(std::string cpf) { this->cpf = cpf; }
void Astronaut::setAge(int age) { this->age = age; }
void Astronaut::setAvailable(bool available) { this->available = available; }
