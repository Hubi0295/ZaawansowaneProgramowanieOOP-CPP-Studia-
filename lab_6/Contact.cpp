//
// Created by Daniel on 2024-11-17.
//

#include "Contact.h"

Contact::Contact() {
}

Contact::Contact(string imie, string nazwisko, int wiek, string numer_tel, string ulica) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->numer_tel=numer_tel;
    this->ulica=ulica;
    this->wiek=wiek;
}
void Contact::operator()(int age1, int age2) const {
    if (wiek >= age1 && wiek <= age2) {
        cout << "imie: " << imie << endl;
        cout << "nazwisko: " << nazwisko << endl;
        cout << "wiek: " << wiek << endl;
        cout << "numer: " << numer_tel << endl;
        cout << "ulica: " << ulica << endl;
        cout << endl;
    }
}