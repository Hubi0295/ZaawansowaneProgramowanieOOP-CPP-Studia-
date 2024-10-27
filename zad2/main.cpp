

#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

#include "City.h"

using namespace std;
void showCities(vector<City> c);
void the_most(vector<City> c, int mode);
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
    c.addCitizen(Citizen("jane","kowalska",15,'W',"21-111"));
    c.addCitizen(Citizen("Marine","Smiech",25,'W',"21-111"));
    cout<<c.adults()<<endl;
    cout<<c.women()<<endl;
    cout<<c.city_citizens()<<endl;
    c.deleteCitizen("kowalska",15);
    c.show_citizens();
    c.postal_codes();
    return 0;
}
