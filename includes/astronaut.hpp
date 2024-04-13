#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <string>

class Astronaut {
private:
  std::string name;
  std::string cpf;
  int age;

public:
  Astronaut();
  Astronaut(std::string cpf, std::string name, int age);

  std::string getName();
  std::string getCpf();
  int getAge();

  void setName(std::string name);
  void setCpf(std::string cpf);
  void setAge(int age);
};
#endif