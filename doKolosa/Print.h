//
// Created by Daniel on 2024-11-17.
//

#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;
class Print {
public:
  template<typename T>
  void operator()(T t){
   cout<<t<<endl;
  }
};



#endif //PRINT_H
