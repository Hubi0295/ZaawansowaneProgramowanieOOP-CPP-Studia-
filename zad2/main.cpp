

#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>
#include "City.h"

using namespace std;
City c1("bbb");
City c2("bbb");
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

void the_most(vector<City> c, int mode) {
    switch(mode) {
        case 0: for_each(c.begin(),c.end(),maxPostalCodeNumber);;break;
        default:break;
    }
}
void statistics(vector<City> c);
void sort_cities(vector<City> &c);
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
using namespace std;
int main()
{
    list<int> listt;
    dodawaj(listt,rand()%1000);
    show(listt);

    City c("New york");
    c.addCitizen(Citizen("jack","nowak",22,'M',"21-111"));
    c.addCitizen(Citizen("jane","kowalska",15,'W',"21-112"));
    c.addCitizen(Citizen("Marine","Smiech",25,'W',"21-113"));
    c.addCitizen(Citizen("jack","nowak",22,'M',"21-111"));
    c.addCitizen(Citizen("jane","kowalskaa",15,'W',"21-112"));
    c.addCitizen(Citizen("Marine","Smiech",25,'W',"21-113"));
    c.addCitizen(Citizen("jack","nowak",22,'M',"21-113"));
    c.addCitizen(Citizen("jane","kowalskaa",15,'W',"21-114"));
    c.addCitizen(Citizen("Marine","Smiech",25,'W',"21-115"));
    c.addCitizen(Citizen("jack","nowak",22,'M',"21-112"));
    c.addCitizen(Citizen("jane","kowalskaa",15,'W',"21-113"));
    c.addCitizen(Citizen("Marine","Smiech",25,'W',"21-112"));
    cout<<c.adults()<<endl;
    cout<<c.women()<<endl;
    cout<<c.city_citizens()<<endl;
    c.deleteCitizen("kowalska",15);
    c.show_citizens();
    c.postal_codes();

    vector<City> cities;
    cities.push_back(City("new york"));
    cities.push_back(City("berlin"));
    cities.push_back(City("lublin"));
    showCities(cities);

    vector<City> cities2;
    City city1("New york");
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-112")));
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-112")));
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-113")));
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-113")));
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-113")));
    city1.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-111")));
    city1.postal_codes();
    cities2.push_back(city1);
    City city2("Lublin");
    city2.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-111")));
    city2.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-112")));
    city2.addCitizen(Citizen(Citizen("Marine","Smiech",25,'W',"21-111")));
    city2.postal_codes();
    cities2.push_back(city2);

    c1.postal_codes();
    the_most(cities2,0);

    cout<<endl;
    c1.show_city();
    return 0;

}
