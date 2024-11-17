//
// Created by Daniel on 2024-11-17.
//

#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

using namespace std;
class Contact {
public:
    string imie;
    string nazwisko;
    int wiek;
    string numer_tel;
    string ulica;
    Contact();
    Contact(string imie,string nazwisko,int wiek, string numer_tel,string ulica);
    void operator()(int age1, int age2) const;
};



#endif //CONTACT_H
