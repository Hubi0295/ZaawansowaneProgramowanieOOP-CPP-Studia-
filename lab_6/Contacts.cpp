#include "Contacts.h"

Contacts::Contacts() {}

bool czyDorosle(const Contact& contact) {
    return contact.wiek >= 18;
}

void zmienNazweUlicy(Contact& kontakt, const string& nowa_ulica) {
    kontakt.ulica = nowa_ulica;
}

void wyswietlKontakt(const Contact& kontakt) {
    cout << "imie: " << kontakt.imie << endl;
    cout << "nazwisko: " << kontakt.nazwisko << endl;
    cout << "wiek: " << kontakt.wiek << endl;
    cout << "numer: " << kontakt.numer_tel << endl;
    cout << "ulica: " << kontakt.ulica << endl << endl;
}

void Contacts::add_contact(Contact c) {
    if (ksiazka_adresowa.get<2>().count(c.numer_tel) == 0) {
        ksiazka_adresowa.insert(c);
    } else {
        cout << "Ktos o takim numerze tel istnieje" << endl;
    }
}

void Contacts::delete_contact(string numb) {
    auto it = ksiazka_adresowa.get<2>().find(numb);
    if (it != ksiazka_adresowa.get<2>().end()) {
        ksiazka_adresowa.get<2>().erase(it);
    } else {
        cout << "Nie znaleziono kontaktu z numerem: " << numb << endl;
    }
}

void Contacts::get_by_ulica(string ulica) {
    auto& ulica_index = ksiazka_adresowa.get<3>();
    auto range = ulica_index.equal_range(ulica);
    for (auto it = range.first; it != range.second; ++it) {
        wyswietlKontakt(*it);
    }
}

void Contacts::get_by_age(int age1, int age2) {
    auto& wiek_index = ksiazka_adresowa.get<1>();
    for (const auto& kontakt : wiek_index) {
        if (kontakt.wiek >= age1 && kontakt.wiek <= age2) {
            wyswietlKontakt(kontakt);
        }
    }
}

void Contacts::get_by_number(string numb) {
    auto it = ksiazka_adresowa.get<2>().find(numb);
    if (it != ksiazka_adresowa.get<2>().end()) {
        wyswietlKontakt(*it);
    } else {
        cout << "Nie znaleziono kontaktu z numerem: " << numb << endl;
    }
}

void Contacts::changeStreetName(const string currentStreet, const string newStreet) {
    auto& ulica_index = ksiazka_adresowa.get<3>();
    auto range = ulica_index.equal_range(currentStreet);
    vector<contact_multi::iterator> to_modify;
    for (auto it = range.first; it != range.second; ++it) {
        to_modify.push_back(ksiazka_adresowa.project<0>(it));
    }
    for (auto it : to_modify) {
        ksiazka_adresowa.modify(it, boost::bind(zmienNazweUlicy, _1, newStreet));
    }
}


void Contacts::adult() {
    int ile = count_if(ksiazka_adresowa.get<4>().begin(), ksiazka_adresowa.get<4>().end(), czyDorosle);
    cout << "doroslych: " << ile << endl;
}

void Contacts::uniqueNazwisko() {
    cout << "Unikatowych " << ksiazka_adresowa.get<5>().size() << endl;
}

void Contacts::show() {
    for (const auto& kontakt : ksiazka_adresowa) {
        wyswietlKontakt(kontakt);
    }
}