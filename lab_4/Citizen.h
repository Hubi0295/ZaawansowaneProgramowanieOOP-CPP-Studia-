

#ifndef CITIZEN_H
#define CITIZEN_H
#include <string>

#include "stdio.h"

using namespace std;
class Citizen {
private:
  string name;
  string surname;
  int age;
  char sex;
  string postal_code;
public:
  Citizen();
  Citizen(string name, string surname, int age, char sex, string postal_code);
  void static show(Citizen c);

  string get_name();
  string get_surname();
  int get_age();
  char get_sex();
  string get_postal_code();

  void set_name(string name);
  void set_surname(string surname);
  void set_age(int age);
  void set_sex(char sex);
  void set_postal_code(string postal_code);
};



#endif //CITIZEN_H
