//
// Created by Daniel on 2024-10-12.
//

#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee
{
public:
    Developer(string surname1, int age1, int experience1, float salary1);
    Developer();
    ~Developer();
    int calculateBonus(int value) override;
};


#endif //DEVELOPER_H
