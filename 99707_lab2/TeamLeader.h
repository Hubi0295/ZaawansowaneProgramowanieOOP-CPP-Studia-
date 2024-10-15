

#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Employee.h"


class TeamLeader: public Employee {
public:
    TeamLeader(string surname1,int age1, int experience1,float salary1);
    TeamLeader();
    ~TeamLeader();
    int calculateBonus(int value) override;
    void show() override;
};



#endif //TEAMLEADER_H
