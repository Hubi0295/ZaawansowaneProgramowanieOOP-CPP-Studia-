#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include "Dictionary.h"
using namespace std;
pair <set<int>::iterator, bool> funkcja(vector<int> m) {
    pair <set<int>::iterator, bool> res;
    set<int> bb;
    int suma=0;
    for(vector<int>::iterator it = m.begin(); it != m.end(); it++) {
        res = bb.insert(*it);
        if(res.second==1) {
            suma+=*(res.first);
        }
        else {
            cout<<"Zduplikowana wartosc: "<<*(res.first)<<endl;
        }
    }
    cout<<"Suma: "<<suma<<endl;
    return res;
}
template<typename T>
void zad2(set<T> a, set<T> b) {
    set<T> result;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
    cout << "Alternatywa wykluczajaca:" << endl;
    for(auto itr = result.begin(); itr != result.end(); itr++) {
        cout<<*itr<<endl;
    }
    cout << endl;
}
char zad3(string a1, string a2) {
    map<char,int> mapa;
    for(char x:a1) {
        if(mapa.find(x)==mapa.end()) {
            mapa[x]=1;
        }
        else {
            mapa.at(x)=mapa[x]+1;
        }
    }
    for(char x:a2) {
        if(mapa.find(x)==mapa.end()) {
            mapa[x]=1;
        }
        else {
            mapa.at(x)=mapa[x]-1;
        }
    }
    for(map<char,int>::iterator i= mapa.begin(); i!=mapa.end(); i++) {
        if(i->second!=0) {
            return i->first;
        }
    }
    return '0';
}

int main() {
    vector<int> abc= {1,2,3,4,5,6,7,8,1,1,1,1};
    pair<set<int>::iterator,bool> a=funkcja(abc);
    cout<<*(a.first)<<" "<<a.second<<endl;

    set<int> a1={1,2,3,4,5};
    set<int> a2={3,4,5,6,7};
    zad2<int>(a1,a2);
    cout<<"Jeden znak wiecej: "<<zad3("abcdef","abcdefx")<<endl;

    Dictionary *d = new Dictionary();
    d->add("hello","czesc");
    d->add("tea","herbata");
    d->showAll();
    d->deleteWord("tea");
    d->showAll();
    d->showWord("hello");
    cout<<endl;
    d->add("water","woda");
    d->add("zip","suwak");
    d->add("car","samochod");
    d->add("hammer","mlotek");

    d->showSortedByExplain();
    return 0;
}
