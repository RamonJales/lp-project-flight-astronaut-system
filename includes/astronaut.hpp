#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <string>

class Astronaut {
private:
  int id;
  std::string name;
  std::string cpf;
  int age;
  bool available;

public:
  Astronaut();
  Astronaut(int id, std::string cpf, std::string name, int age, bool available);

  int getId();
  std::string getName();
  std::string getCpf();
  int getAge();
  bool isAvailable();

  void setName(std::string name);
  void setCpf(std::string cpf);
  void setAge(int age);
  void setAvailable(bool available);
};
#endif