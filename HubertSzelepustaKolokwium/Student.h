//
// Created by Hubert on 13.12.2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <map>
#include <string>
#include <iostream>
#include "subject.h"
using namespace std;
template<typename T>
class Student {
private:
    string name;
    string surname;
    long id;
    map<subject,T> oceny;
public:
    Student();
    Student(string name, string surname, long id, map<subject,T> x) {
        this->name=name;
        this->surname=surname;
        this->id=id;
        this->oceny=x;
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    long getId() {
        return id;
    }
    map<subject, T> getOceny() {
        return oceny;
    }
    void setName(string name) {
        this->name = name;
    }
    void setSurname(string surname) {
        this->surname=surname;
    }
    void setId(long id) {
        this->id=id;
    }
    void setOceny(map<subject, T> x) {
        this->oceny=x;
    }
    void show_all_grades();
};
#endif //STUDENT_H
template<>
void Student<int>::show_all_grades() {
    for(map<subject,int>::iterator it=oceny.begin(); it!=oceny.end(); it++) {
        cout<<"Ocena: "<<it->second<<endl;
    }
}
template<>
void Student<string>::show_all_grades() {
    for(map<subject,string>::iterator it=oceny.begin(); it!=oceny.end(); it++) {
        cout<<"Ocena w skali opisowej: "<<it->second<<endl;
    }
}
