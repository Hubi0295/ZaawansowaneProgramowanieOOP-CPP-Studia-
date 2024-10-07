//
// Created by Daniel on 2024-10-07.
//

#ifndef STUDENT_H
#define STUDENT_H


#include "Person.h"
class Student: public Person {
private:
    string index;
public:
    Student(string name1, string surname1, int age1, string index1);
    Student();
    void setIndex(string index1);
    string getIndex();
    void showInfoStudent();
};



#endif //STUDENT_H
