//
// Created by Daniel on 2024-10-07.
//

#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"


class Teacher:public Person {
private:
    int experience;
    string title;
public:
    Teacher(string name1,string surname1,int age1, int exp1,string title1);
    Teacher();
    void setTitle(string title1);
    int getExperience();
    bool is_Phd();
    void showInfoTeacher();
};



#endif //TEACHER_H
