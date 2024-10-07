//
// Created by Daniel on 2024-10-07.
//

#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(string name1, string surname1, int age1, string index1)
:Person(name1, surname1, age1) {
    index = index1;
    cout<<"Konstruktor klasy pochodnej- Student"<<endl;
};
Student::Student() {
    cout<<"Konstruktor bez klasy pochodnej- Student"<<endl;
}
void Student::setIndex(string index1) {
    index = index1;
}
string Student::getIndex() {
    return index;
}
void Student::showInfoStudent() {
    showInfoPerson();
    cout<<"index: "<<index<<endl;
}