//
// Created by Daniel on 2024-10-27.
//

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

using namespace std;
class Address {
private:
  std::string postal_code;
  int number_of_citizens;
  public:
  Address();
  Address(string postal_code, int number_of_citizens);
  string getPostalCode();
  int getNumberOfCitizens();
  void increase_number_of_citizens();
};



#endif //ADDRESS_H
