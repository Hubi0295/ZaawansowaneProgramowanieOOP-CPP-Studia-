//
// Created by Daniel on 2024-10-07.
//

#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include <iostream>
using namespace std;
class Dog: public Animal {
private:
    string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;
public:
    Dog();
    Dog(int limbnr1,string name1,bool isProtected, string breed1,int levelOfGuideSkills1,int levelOfTrackerSkills1);
    Dog(string breed1,int levelOfGuideSkills1,int levelOfTrackerSkills1);
    void setSkillLevel(int type, int value);
    int getSkillLevel(int type);
    void getVoice();
    void info();
};



#endif //DOG_H
