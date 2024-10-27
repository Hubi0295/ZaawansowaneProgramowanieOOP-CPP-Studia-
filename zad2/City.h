//
// Created by Daniel on 2024-10-27.
//

#ifndef CITY_H
#define CITY_H
#include <list>

#include "Citizen.h"
#include <vector>
#include "Address.h"
using namespace std;
class City {
private:
  vector<Citizen> citizens;
  string city_name;
public:
  City();
  City(string city_name);
  void addCitizen(Citizen c);
  void deleteCitizen(string surname,int age);
  void show_citizens();
  void show_city();
  int women();
  int city_citizens();
  int adults();
  void postal_codes();


};



#endif //CITY_H
