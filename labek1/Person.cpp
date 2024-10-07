//
// Created by Daniel on 2024-10-07.
//

#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    cout<<"Konstruktor bez klasy bazowej- Person"<<endl;
}
Person::Person(string name1, string surname1, int age1) {
    name=name1;
    surname=surname1;
    age=age1;
    cout<<"Konstrukotr klasy bazowej- Person"<<endl;
}
void Person::setAge(int age1) {
    age=age1;
}
string Person::getSurname() {
    return surname;
}
bool Person::is_18() {
    if(age>=18) {
        return true;
    }
    else {
        return false;
    }
}
void Person::showInfoPerson() {
    cout<<"Imie: "<<name<<" Naziwsko: "<<surname<<" Wiek: "<<age<<endl;
}
void Person::init(string name1, string surname1, int age1) {
    name=name1;
    surname = surname1;
    age=age1;
}

