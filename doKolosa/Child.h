//
// Created by Hubert on 11.12.2024.
//

#ifndef CHILD_H
#define CHILD_H
#include "Parent.h"


class Child:public Parent {
public:
    virtual void show() override;
    Child(){};

};



#endif //CHILD_H
