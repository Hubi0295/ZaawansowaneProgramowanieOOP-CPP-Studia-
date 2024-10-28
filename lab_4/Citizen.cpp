
#include "Citizen.h"

#include <iostream>
#include <ostream>

Citizen::Citizen() {

}
Citizen::Citizen(string name, string surname, int age, char sex, string postal_code) {
    this->name=name;
    this->surname=surname;
    this->age=age;
    this->sex=sex;
    this->postal_code=postal_code;
}
void Citizen::show(Citizen c) {
    cout<<"Name: "<<c.name<<endl;
    cout<<"Surname: "<<c.surname<<endl;
    cout<<"Age: "<<c.age<<endl;
    cout<<"Sex: "<<c.sex<<endl;
    cout<<"Postal Code: "<<c.postal_code<<endl;
    cout<<endl;
}


string Citizen::get_name(){
    return name;
}

string Citizen::get_surname(){
    return surname;
}

int Citizen::get_age(){
    return age;
}

char Citizen::get_sex(){
    return sex;
}

string Citizen::get_postal_code(){
    return postal_code;
}

void Citizen::set_name(string name) {
    this->name = name;
}

void Citizen::set_surname(string surname) {
    this->surname = surname;
}

void Citizen::set_age(int age) {
    this->age = age;
}

void Citizen::set_sex(char sex) {
    this->sex = sex;
}

void Citizen::set_postal_code(string postal_code) {
    this->postal_code = postal_code;
}
