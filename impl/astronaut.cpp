#include "../includes/astronaut.hpp"

Astronaut::Astronaut() {}

Astronaut::Astronaut(int id, std::string cpf, std::string name, int age) {
  this->id = id;
  this->name = name;
  this->cpf = cpf;
  this->age = age;
}

int Astronaut::getId() { return this->id; }
std::string Astronaut::getName() { return this->name; }
std::string Astronaut::getCpf() { return this->cpf; }
int Astronaut::getAge() { return this->age; }

void Astronaut::setName(std::string name) { this->name = name; }
void Astronaut::setCpf(std::string cpf) { this->cpf = cpf; }
void Astronaut::setAge(int age) { this->age = age; }
