//
// Created by Hubert on 20.12.2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    string plec;
    int ocena;
    string mail;
public:
    Student(){};
    Student(string imie, string nazwisko, string plec, int ocena, string mail) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->plec = plec;
        this->ocena = ocena;
        this->mail = mail;
    }
    Student(string imie, string nazwisko, string plec, int ocena) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->plec = plec;
        this->ocena = ocena;
        this->mail = "_";
    }
    void show() {
        cout<<"Imie: "<<imie<<endl;
        cout<<"Nazwisko: "<<nazwisko<<endl;
        cout<<"Plec: "<<plec<<endl;
        cout<<"Ocena: "<<ocena<<endl;
        if(mail != "") {
            cout<<"Mail: "<<mail<<endl;
        }
    }

    string imie1() const {
        return imie;
    }

    string nazwisko1() const {
        return nazwisko;
    }

    string plec1() const {
        return plec;
    }

    int ocena1() const {
        return ocena;
    }

    string mail1() const {
        return mail;
    }
};



#endif //STUDENT_H
