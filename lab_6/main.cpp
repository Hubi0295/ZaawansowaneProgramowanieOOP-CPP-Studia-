#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <map>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include "Print.h"
#include <boost/fusion/container.hpp>
#include <boost/mpl/int.hpp>
#include <boost/fusion/sequence.hpp>
#include <vector>

#include "Contacts.h"
#include "Contact.h"
#include "Person.h"
#include "Operation.h"
using namespace boost::multi_index;
using namespace std;
struct TypeCounter {
    map<string, int>& typeCount;
    explicit TypeCounter(map<string, int>& count) : typeCount(count) {}
    template<typename T>
    void operator()(const T& elem) const {
        string typeName = typeid(elem).name();
        typeCount[typeName]++;
    }
};


map<string, int> zad4(const boost::fusion::vector<int, double, float, bool, char>& vec) {
    map<string, int> typeCount;
    boost::fusion::for_each(vec, TypeCounter(typeCount));
    return typeCount;
}
template <typename T>
void checkzad3(T val1, float val2) {
    if (val1 < val2) { // poprawiono warunek
        cout << " " << val1 << " " << endl;
    }
}
template <typename T>
struct CzyDodatnie {
    void operator()(T val1) const {
        if (val1 > 0) {
            std::cout << "Dodatnie: " << val1 << " " << std::endl;
        }
    }
};
template <typename T>
struct pomiedzy {
    T mean;
    T med;
    pomiedzy(T mean, T med) : mean(mean), med(med) {}
    void operator()(const T& val) const {
        if (val > mean && val < med) {
            std::cout << val << " ";
        }
    }
};
template <typename T>
void statystyka(vector<T> vec) {
    float suma=0;
    for(auto it=vec.begin(); it!=vec.end(); it++) {
        suma+=*it;
    }
    float srednia = suma / vec.size();

    std::vector<T> temp = vec; // Kopia wektora do obliczenia mediany
    std::sort(temp.begin(), temp.end());
    T mediana = (temp.size() % 2 == 0)? (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / T(2): temp[temp.size() / 2];


    std::cout << "Elementy mniejsze niz średnia arytmetyczna (" << srednia << "):" << std::endl;
    std::for_each(vec.begin(), vec.end(), std::bind(checkzad3<T>, std::placeholders::_1, srednia));

    // Elementy między średnią a medianą
    std::for_each(vec.begin(), vec.end(), pomiedzy<T>(srednia, mediana));

    std::cout << std::endl;

    // Elementy dodatnie
    std::cout << "Elementy dodatnie:" << std::endl;
    std::for_each(vec.begin(), vec.end(),CzyDodatnie<T>());
}
void firstArgMod(int &x, int y) {
    x = x + y;
}

void printF(int x) {
    cout << x << " ";
}

void contatination(int i1, int i2) {
    cout << i1 << i2 << endl;;
}

int addition(int a, int b) {
    return a + b;
}

void UlaToUrszula(Person &x) {
    x.name = "Urszula";
}

void AlaToAlicja(Person &x) {
    if (x.name == "Ala")
        x.name = "Alicja";
}

typedef multi_index_container<Person, indexed_by<
    hashed_non_unique<member<Person, string, &Person::name> >,
    hashed_non_unique<member<Person, int, &Person::age> >
> > person_multi;
typedef person_multi::nth_index<0>::type name_type;
typedef person_multi::nth_index<1>::type age_type;

typedef multi_index_container<Person, indexed_by<
    ordered_non_unique<member<Person, string, &Person::name> >,
    ordered_non_unique<member<Person, int, &Person::age> >,
    random_access<> > > person_multi_2;
typedef person_multi_2::nth_index<0>::type name_type2;
typedef person_multi_2::nth_index<1>::type age_type2;

int main() {
    person_multi persons;
    persons.insert({"Ala", 40});
    persons.insert({"Piotr", 10});
    persons.insert({"Ola", 18});
    persons.insert({"Ala", 46});
    persons.insert({"Ula", 46});

    cout << "Liczba osob o imieniu Ala: " << persons.count("Ala") << endl;
    cout << "Liczba osob o imieniu Ala: " << persons.get<0>().count("Ala") << endl;

    age_type &age_index = persons.get<1>();

    cout << "Liczba osob z wiekiem 18 lat: " << age_index.count(18) << endl;

    for (name_type::iterator it = persons.get<0>().begin(); it != persons.get<0>().end(); ++it)
        it->show();

    auto &age_indexx = persons.get<1>();
    auto it = age_indexx.find(46);
    cout << "Znaleziona osoba, ktora ma 46 lat "
            << it->name << endl;

    auto &name_indexx = persons.get<0>();
    auto itt = name_indexx.find("Ula");
    name_indexx.modify(itt, boost::bind(UlaToUrszula, _1));

    auto itt2 = name_indexx.find("Ala");
    name_indexx.modify(itt2, boost::bind(AlaToAlicja, _1));

    for (name_type::iterator it = persons.get<0>().begin(); it != persons.get<0>().end(); ++it)
        it->show();

    person_multi_2 persons2;
    persons2.get<2>().push_back({"Ala", 40});
    persons2.get<2>().push_back({"Ala", 45});
    persons2.get<2>().push_back({"Piotr", 10});
    persons2.get<2>().push_back({"Ola", 18});
    persons2.get<2>().push_back({"Aga", 46});
    persons2.get<2>().push_back({"Ula", 46});
    auto &name_indexx2 = persons2.get<0>();
    auto iterStart = name_indexx2.equal_range("Ala");
    auto iterStop = name_indexx2.equal_range("Piotr");
    cout << "przedzial od Ala do Piotr - wersja 1" << endl;

    for (name_type2::iterator it = iterStart.first;
         it != iterStop.second; ++it)
        it->show();
    auto from = name_indexx2.lower_bound("Ala");
    auto to = name_indexx2.upper_bound("Piotr");
    cout << "przedzial od Ala do Piotr - wersja 2" << endl;
    for (auto it = from; it != to; ++it)
        it->show();

    auto &rand_indexx = persons2.get<2>();
    cout << rand_indexx[0].name << endl;

    boost::fusion::vector<int, string, bool, double> vec{
        10,
        "C++", true, 3.14
    };
    cout << "Trzeci element w vec:"
            << boost::fusion::at<boost::mpl::int_<2> >(vec) << endl;
    auto vec2 = push_back(vec, 'M');
    cout << "Liczba elementow w wvec: " << size(vec) << endl;
    cout << "Liczba elementow w vec2: " << size(vec2) << endl;
    cout << "Pierwszy element w vec2: " << front(vec2) << endl;
    cout << "Ostatni element w vec2: " << back(vec2) << endl;
    cout << "Cala zawartosc vec2: " << endl;
    boost::fusion::for_each(vec2, Print());

    auto itvStart = begin(vec);
    auto itvStop = end(vec);
    cout << "Pierwszy element: " << *itvStart << endl;
    cout << "Drugi element: " << *next(itvStart) << endl;
    cout << "Trzeci element: "<< *advance<boost::mpl::int_<2> >(itvStart) << endl;


    cout << "vec: " << endl;
    vector<int> vec10 = {1, 2, 3, 4, 5};
    vector<int>::iterator iter1 = vec10.begin();
    vector<int>::iterator iter2 = vec10.end();
    for_each(iter1, iter2, boost::bind(printF, _1));
    cout << endl << "vec - kazdy element zwiekszony o 5: ";
    for_each(iter1, iter2, boost::bind(firstArgMod, _1, 5));
    for_each(iter1, iter2, boost::bind(printF, _1));
    int count = std::count_if(vec10.begin(), vec10.end(),
                              boost::bind(std::logical_and<bool>(),
                                          boost::bind(std::greater<int>(), _1, 8),
                                          boost::bind(std::less_equal<int>(), _1, 10)));
    cout << endl << "vec - 8<Elementy<=10 " << count << endl;

    cout << addition(1, 2) << endl;
    int res = boost::bind(addition, _1, _2)(1, 2);
    cout << res << endl;

    int i1 = 1, i2 = 2;
    boost::bind(contatination, _2, _1)(i1, i2);

    Operation ff;
    int x = 1024;
    cout << "Funktor: " << boost::bind<int>(ff, _1, _2)(x, 6) << endl;
    char y = 'a';
    cout << "Funktor: " << boost::bind<char>(ff, _1)(y) << endl;


    Contacts *c;
    c = new Contacts();
    c->add_contact(Contact("marek","kowalski",22,"123123123","kolejowa"));
    c->add_contact(Contact("tadek","nowak",12,"443226112","oscienna"));
    c->add_contact(Contact("jurek","lewandowski",43,"345543123","kolejowa"));
    c->show();
    cout<<"aaa"<<endl;
    c->delete_contact("123123123");
    cout<<"Po usunieciu"<<endl;
    c->show();
    c->add_contact(Contact("marek","ted",22,"123123123","kolejowa"));

    cout<<"Lista osob mieszkajacych na kolejowej"<<endl;
    c->get_by_ulica("kolejowa");
    cout<<"Pomiedzy wiekiem"<<endl;
    c->get_by_age(20,43);
    cout<<"Znajdz po nr tel"<<endl;
    c->get_by_number("123123123");
    cout<<"Zmiana nazwy ulicy"<<endl;
    c->changeStreetName("kolejowa","kwiatowa");
    c->show();
    cout<<"Unikalne naziwska"<<endl;
    c->uniqueNazwisko();
    cout<<"doroslych"<<endl;
    c->adult();


    cout<<endl;
    vector<int> vec1={-2,-1,0,1,2,3,4,5,15};
    statystyka(vec1);
    boost::fusion::vector< int, double, float, bool, char> vec19{1,2.9,2.7,true,'a'};
    map<string,int> mapa = zad4(vec19);
    for(map<string,int>::iterator it=mapa.begin();it!=mapa.end();it++) {
        cout<<"Klucz:"<<it->first<<" Wartosc:"<<it->second<<endl;
    }
    return 0;
}
