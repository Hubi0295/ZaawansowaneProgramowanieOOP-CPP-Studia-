
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "Compare.h"
#include "Even.h"
#include <list>
#include <ostream>
#include "City.h"
#include "CompareByNumberCitizens.h"
#include "CompareByNumberDigits.h"
#include "CompareBySumDigits.h"

using namespace std;
City c1;
City c2;
void showCities(vector<City> &c) {
    for(vector<City>::iterator it = c.begin(); it != c.end(); it++) {
        it->show_city();
    }
}
void maxPostalCodeNumber(City &c) {
    list<Address> maxPostalCode = c.get_lista_adresow();
    if(maxPostalCode.size() > c1.get_lista_adresow().size()) {
        c1=c;
    }
}
void minNumberOfCitizens(City &c) {
    if(c.get_citizens().size()<c2.get_citizens().size()) {
        c2=c;
    }
}
void the_most(vector<City> c, int mode) {
    switch(mode) {
        case 0: c1=c.front();for_each(c.begin(),c.end(),maxPostalCodeNumber);break;
        case 1: c2=c.front();for_each(c.begin(),c.end(),minNumberOfCitizens);break;
        default:break;
    }
}
void statistics(vector<City> c) {
    for(vector<City>::iterator it = c.begin(); it != c.end(); it++) {
        cout<<endl<<"Nazwa miasta: ";it->show_city();
        cout<<"Liczba mieszkancow: "<<it->get_citizens().size()<<endl;
        cout<<"Liczba kobiet: "<<it->women()<<endl;
        cout<<"Liczba mezczyzn: "<<it->get_citizens().size()-it->women()<<endl;
        cout<<"Liczba osob pelnoletnich: "<<it->adults()<<endl;
        cout<<"Liczba osob niepelnoletnich: "<<it->get_citizens().size()-it->adults()<<endl;
    }
}

void sort_cities(vector<City> &c) {
    sort(c.begin(),c.end(),CompareByNumberCitizens());
}
template<typename T>
void show(T &con) {
    for(typename T::iterator it = con.begin(); it != con.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
template<typename T>
void dodawaj(list<T> &l, int n) {
    int x = l.size();
    while(x<n) {
        int losowa=rand()%200-100;
        if(losowa<0) {
            l.push_back(losowa);
        }
        else {
            l.push_front(losowa);
        }
        x+=1;
    }
}
void print(int &x) {
    cout<<x<<" ";
}

void add10(int &el) {
    el=el+10;
}
bool isEven(int x) {
    if(x % 2 == 0) {
        return true;
    }
    return false;
}
void showMark(Student &s) {
    cout<<s.getMark()<<" "<<endl;
}
int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout<<"Operator[]"<<endl;
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" "<<endl;
    }
    cout<<endl;

    cout<<"At"<<endl;
    for(int i=0;i<vec.size();i++) {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;

    cout<<"Iterator: "<<endl;
    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++) {
        cout<<*it<<endl;
    }
    cout<<endl;

    cout<<"begin() "<<*vec.begin()<<" front()"<<vec.front()<<endl;
    cout<<"end() "<<*(vec.end()-1)<<" back() "<<vec.back()<<endl;

    show(vec);
    vec.pop_back();
    show(vec);
    vec.erase(vec.begin()+1,vec.begin()+2);
    show(vec);
    vec.insert(vec.begin()+1,100);
    show(vec);
    vec.clear();
    show(vec);

    vector<float>vec2(5,8.2);
    show(vec2);
    vec2.push_back(3.1);
    show(vec2);

    vector<int>num={3,6,3,8,9,1,3};
    show(num);
    sort(num.begin(),num.end());
    show(num);

    cout<<"binary search"<<endl;
    cout<<binary_search(num.begin(),num.end(),3)<<endl;

    cout<<"count"<<endl;
    cout<<count(num.begin(),num.end(),3)<<endl;

    cout<<"reverse"<<endl;
    reverse(num.begin(),num.begin()+4);
    show(num);

    cout<<"random_shuffle"<<endl;
    shuffle(num.begin(),num.end(), std::mt19937(std::random_device()()));
    show(num);

    cout<<"max element"<<endl;
    cout<<*max_element(num.begin(),num.end())<<endl;

    cout<<"merge"<<endl;
    vector<int>num2(4,6);
    vector<int>res(num.size()+num2.size());
    sort(num.begin(),num.end());
     merge(num.begin(),num.end(),num2.begin(),
    num2.end(),res.begin());
     show(res);

    for_each(num.begin(),num.end(),print);
    for_each(num.begin(),num.end(),add10);
    cout<<endl;
    for_each(num.begin(),num.end(),print);
    cout<<endl;
    cout<<count_if(num.begin(),num.end(),isEven);


    vector<int> num3={2, -6, 7, 3, 0, 8, -9, -2};
    for_each(num3.begin(),num3.end(),print);
    int howMany=count_if(num3.begin(),num3.end(),bind2nd(greater<int>(),0));
    cout<<endl<<"wersja1: wartosc>0 "<<howMany<<endl;
    greater<int> f;
    howMany = count_if(num3.begin(),num3.end(),bind2nd(f,0));
    cout<<"wersja2: wartosc>0 "<<howMany<<endl;

    cout<<"Przed sortowaniem"<<endl;
    for_each(num3.begin(),num3.end(),print);
    sort(num3.begin(),num3.end(),greater<int>());
    cout<<endl<<"Po sortowaniu"<<endl;
    for_each(num3.begin(),num3.end(),print);
    cout<<endl;

    for_each(num.begin(),num.end(),print);
    cout<<endl;
    cout<<count_if(num.begin(),num.end(),isEven)<<endl;
    cout<<count_if(num.begin(),num.end(),Even(2))<<endl;

    cout<<endl;
    vector<Student>st;
    st.push_back(Student(1,"Ala"));
    st.push_back(Student(5,"Ola"));
    st.push_back(Student(2,"Piotr"));
    for_each(st.begin(),st.end(),showMark);
    cout<<endl;
    sort(st.begin(),st.end(),Compare());
    for_each(st.begin(),st.end(),showMark);


    //zad2
    list<int> listt;
    dodawaj(listt,rand()%1000);
    show(listt);
    cout<<endl;

    //zad3
    vector<City> cities2;

    City city1("New york");
    city1.addCitizen(Citizen(Citizen("Jack","Sparrow",25,'M',"21-112")));
    city1.addCitizen(Citizen(Citizen("Mike","Pol",15,'M',"21-112")));
    city1.addCitizen(Citizen(Citizen("Janick","Speer",26,'M',"21-100")));
    city1.addCitizen(Citizen(Citizen("Monica","Kowalczyk",25,'W',"21-100")));
    city1.addCitizen(Citizen(Citizen("Ela","Siewiera",10,'W',"21-100")));
    city1.addCitizen(Citizen(Citizen("Joanna","Ult",88,'W',"21-111")));
    city1.postal_codes();
    cities2.push_back(city1);

    City city2("Berlin");
    city2.addCitizen(Citizen("Hans", "Müller", 34, 'M', "10-101"));
    city2.addCitizen(Citizen("Anna", "Schmidt", 28, 'W', "10-101"));
    city2.addCitizen(Citizen("Uwe", "Becker", 42, 'M', "10-102"));
    city2.addCitizen(Citizen("Lena", "Fischer", 22, 'W', "10-102"));
    city2.addCitizen(Citizen("Klaus", "Schneider", 30, 'M', "10-103"));
    city2.addCitizen(Citizen("Ingrid", "Weber", 15, 'W', "10-103"));
    city2.addCitizen(Citizen("Mark", "Weber", 15, 'M', "10-108"));

    city2.postal_codes();
    cities2.push_back(city2);

    City city3("Lublin");
    city3.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-111")));
    city3.addCitizen(Citizen(Citizen("John","Snow",10,'M',"21-111")));
    city3.addCitizen(Citizen(Citizen("Thomas","Partey",25,'M',"21-112")));
    city3.addCitizen(Citizen(Citizen("Pite","Moroon",10,'M',"21-113")));

    city3.postal_codes();
    cities2.push_back(city3);

    c1.postal_codes();
    c2.postal_codes();


    the_most(cities2,1);
    the_most(cities2,0);

    cout<<endl;
    cout<<"Najwieksza liczba adresow: ";c1.show_city();cout<<endl;
    cout<<"Najmniejsza liczba mieszkancow: ";c2.show_city();cout<<endl;

    statistics(cities2);
    cout<<"Przed sortowaniem: "<<endl;
    showCities(cities2);
    sort_cities(cities2);
    cout<<"Po sortowaniu: "<<endl;
    showCities(cities2);

    //zad4
    vector<int> kontener={111,222,333,444,555,666,111,222,333,777,11,0,1111};
    cout<<"Przed sortowaniem rosnaca wedlug sumy cyfr: "<<endl;
    for_each(kontener.begin(),kontener.end(),print);
    cout<<endl;
    cout<<"Po sortowaniu rosnaco wedlug sumy cyfr: "<<endl;
    sort(kontener.begin(),kontener.end(),CompareBySumDigits());
    for_each(kontener.begin(),kontener.end(),print);
    cout<<endl;
    cout<<"Przed sortowaniem malejaco wedlug liczby cyfr: "<<endl;
    for_each(kontener.begin(),kontener.end(),print);
    cout<<endl;
    cout<<"Po sortowaniu malejaco wedlug liczby cyfr:"<<endl;
    sort(kontener.begin(),kontener.end(),CompareByNumberDigits());
    for_each(kontener.begin(),kontener.end(),print);
    return 0;
}
