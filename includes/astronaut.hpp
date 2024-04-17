#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <string>

class Astronaut {
private:
  int id;
  std::string name;
  std::string cpf;
  int age;

public:
  Astronaut();
  Astronaut(int id, std::string cpf, std::string name, int age);

  int getId();
  std::string getName();
  std::string getCpf();
  int getAge();

  void setName(std::string name);
  void setCpf(std::string cpf);
  void setAge(int age);
};
#endif