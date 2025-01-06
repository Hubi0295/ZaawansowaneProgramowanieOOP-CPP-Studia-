//
// Created by Hubert on 11.12.2024.
//

#ifndef PARENT_H
#define PARENT_H
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void show();
    Parent(){};
    virtual ~Parent(){cout<<"Bye"<<endl;};
};



#endif //PARENT_H
