//
// Created by Daniel on 2024-11-17.
//

#ifndef CONTACTS_H
#define CONTACTS_H
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index_container.hpp>
#include <iostream>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/bind.hpp>

#include "Contact.h"

using namespace boost::multi_index;
using namespace std;
class Contacts {
public:
    typedef multi_index_container<Contact,indexed_by<
    hashed_non_unique<member<Contact, string, &Contact::nazwisko>>,
    hashed_non_unique<member<Contact, int, &Contact::wiek>>,
    hashed_non_unique<member<Contact, string, &Contact::numer_tel>>,
    hashed_non_unique<member<Contact, string, &Contact::ulica>>,
    random_access<>,
    hashed_unique<member<Contact, string, &Contact::nazwisko>>
    >> contact_multi;

    typedef contact_multi::nth_index<0>::type nazwisko_type;
    typedef contact_multi::nth_index<1>::type wiek_type;
    typedef contact_multi::nth_index<2>::type numer_type;
    typedef contact_multi::nth_index<3>::type ulica_type;
    typedef contact_multi::nth_index<4>::type jak_vector;
    typedef contact_multi::nth_index<5>::type jak_set_nazw;
public:
    contact_multi ksiazka_adresowa;
    Contacts();
    void add_contact(Contact c);
    void delete_contact(string numb);
    void get_by_ulica(string ulica);
    void get_by_age(int age1, int age2);
    void get_by_number(string numb);
    void changeStreetName(string currentStreet, string newStreet);
    void adult();
    void uniqueNazwisko();
    void show();
};



#endif //CONTACTS_H
