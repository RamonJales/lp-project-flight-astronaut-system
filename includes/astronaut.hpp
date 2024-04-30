#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <string>
#include <list>
#include "enums/AstronautStateEnum.hpp"

class Astronaut {
private:
  int id;
  std::string name;
  std::string cpf;
  int age;
  bool available;
  AstronautStateEnum astronautState;
  std::list<int> flightCodes;

public:
  Astronaut();
  Astronaut(int id, std::string cpf, std::string name, int age, bool available, AstronautStateEnum astronautState, std::list<int> flightCodes);

  int getId();
  std::string getName();
  std::string getCpf();
  int getAge();
  bool isAvailable();
  AstronautStateEnum getAstronautState();
  std::list<int> getFlightCodes();

  void setName(std::string name);
  void setCpf(std::string cpf);
  void setAge(int age);
  void setAvailable(bool available);
  void setAstronautState(AstronautStateEnum astronautState);
};
#endif