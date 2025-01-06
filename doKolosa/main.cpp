#include <iostream>
#include "Adding.h"
#include "Child.h"
#include "Circle.h"
#include "Parent.h"
#include "Square.h"
#include "Student.h"
#include <limits>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index//hashed_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>
#include <boost/mpl/int.hpp>
#include "Person.h"
#include <map>
#include <set>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <vector>
#include "Compare.h"
#include "Even.h"
#include "Operation.h"
#include "Print.h"

using namespace boost::multi_index;
template<typename T>
void swapIt(T &a, T &b) {
    T temp=a;
    a=b;
    b=temp;
}
template<typename T>
void showAll(T*tab[], int n) {
    for(int i=0;i<n;i++) {
        tab[i]->show();
    }
}
template<typename T>
void checkType(T a) {
    cout<<numeric_limits<T>::min()<<endl;
}
template<typename T>
void show(T &con) {
    for(typename T::iterator it=con.begin();it!=con.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void print(int &el) {
    cout<<el<<"***";
}
void add10(int &el) {
    el+=10;
}
bool isEven(int x) {
    if(x%2==0) {
        return true;
    }
    else {
        return false;
    }
}
template<typename T>
void showMark(Student<T> &s) {
    cout<<s.getMark()<<" ";
}
void show(set<int> s) {
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void showSet(set<int> x) {
    for(set<int>::iterator it=x.begin();it!=x.end();it++) {
        cout<<*it<<" ";
    }
}
void showMap(map<string,int> m) {
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++) {
        cout<<"first: "<<it->first<<" "<<" second: "<<it->second<<endl;
    }
}
map<string,int>::iterator searchByValue(map<string,int> &m, int val) {
    map<string,int>::iterator it;
    for(it = m.begin(); it!= m.end(); it++) {
        if(it->second == val) {
            break;
        }
    }
    return it;
}


typedef multi_index_container<Person,indexed_by<
    hashed_non_unique<member<Person,string, &Person::name>>,
    hashed_non_unique<member<Person, int, &Person::age>>
>>person_multi;
typedef person_multi::nth_index<0>::type name_type;
typedef person_multi::nth_index<1>::type age_type;
//• hashed_non_unique, który działa podobnie jak unordered multiset w STL;
//• hashed_unique, który działa podobnie jak unordered set w STL;
//• ordered_non_unique, który podobnie jak multiset w STL;
//• ordered_unique, który podobnie jak set w STL;
//• sequenced, który działa podobnie jak list w STL;
//• random_access, działa podobnie jak vector w STL.
typedef multi_index_container<Person, indexed_by<
    ordered_non_unique<member<Person, string, &Person::name> >,
    ordered_non_unique<member<Person, int, &Person::age> >,
    random_access<>
>>person_multi_2;
typedef person_multi_2::nth_index<0>::type name_type2;
typedef person_multi_2::nth_index<1>::type age_type2;

void UlaToUrszula(Person &x) {
    x.name="Urszula";
}
void AlaToAlicja(Person &x) {
    if(x.name=="Ala") {
        x.name="Alicja";
    }
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
void firstArgMod(int &x, int y) {
    x = x + y;
}

int main() {
    //lab1
    // Person p1[3]; statyczna tablica statycznych obiektów,
    // Person *p2; dynamiczna tablica statycznych obiektów,
    // Person *p3[3]; statyczna tablica dynamiczna obiektów,
    // Person **p4; dynamiczna tablica dynamiczna obiektów,
    // for(int i=0;i<3;i++) {
    //     p1[i].init("anna", "nowak", 20+i);
    //     p1[i].showInfoPerson();
    // }
    //
    // p2=new Person[3];
    // for(int i=0;i<3;i++) {
    //     p2[i].init("ola", "adamek", 20+i);
    //     p2[i].showInfoPerson();
    // }
    // for(int i=0;i<3;i++) {
    //     p3[i]=new Person("Kasia","kowalska", 20+i);
    //     p3[i]->showInfoPerson();
    // }
    // p4=new Person*[3];
    // for(int i=0;i<3;i++) {
    //     p4[i]=new Person("Pawel","wojcik",20+i);
    //     p4[i]->showInfoPerson();
    // }
    // for(int i=0;i<3;i++) {
    //     delete p4[i];
    // }
    // delete [] p4;

    //lab2 Polimorfizm Dynamiczny
    Parent *p1 = new Parent();
    Parent *p2 = new Child();
    p1->show();
    p2->show();
    delete p1;
    delete p2;

    Figure *f1 = new Square(10);
    Figure *f2 = new Circle(10);
    f1->calculateArea();
    f1->show();
    f2->calculateArea();
    f2->show();
    delete f1;
    delete f2;

    Figure *tab[3];
    tab[0]=new Square(4);
    tab[1]=new Square(2);
    tab[2]=new Square(5);
    for(int i=0;i<3;i++) {
        tab[i]->calculateArea();
        tab[i]->show();
        delete tab[i];
    }

    //lab3 Polimorfizm statyczny
    int a=10;int b=20;
    swapIt<int>(a,b);
    cout<<"A: "<<a<<" B: "<<b<<endl;

    Adding<int>a2(20);
    a2.add(40);
    a2.show();
    Adding<string>s2("Pro");
    s2.add("gram");
    s2.show();

    Student<float> s10(5,"Ala");
    s10.showMark();
    Student<int> s20(5,"Ala");
    s20.showMark();
    Student<string> s30(5,"Ala");
    s30.showMark();

    Adding<int>*arrAdd[3];
    for(int i=0;i<3;i++) {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);
    Student<string>*arrStu[3];
    for(int i=0;i<3;i++) {
        arrStu[i] = new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);
    for(int i=0;i<3;i++) {
        delete arrAdd[i];
        delete arrStu[i];
    }
    checkType<double>(3);


    //lab4 kontenery sekwencyjne
    vector<int> vec22;
    vec22.push_back(1);
    vec22.push_back(2);
    vec22.push_back(3);
    for(int i=0;i<vec22.size();i++) {
        cout<<vec22[i]<<endl;
        cout<<vec22.at(i)<<endl;
    }
    for(vector<int>::iterator it=vec22.begin();it!=vec22.end();it++) {
        cout<<*it<<endl;
    }
    cout<<"begin: "<<*vec22.begin()<<" front: "<<vec22.front()<<" end: "<<*(vec22.end()-1)<<" back: "<<vec22.back()<<endl;
    vec22.pop_back();
    vec22.erase(vec22.begin()+1,vec22.begin()+2);
    vec22.insert(vec22.begin()+1,100);
    show(vec22);
    vec22.clear();
    show(vec22);

    vector<float>vec33(5,8.2);
    show(vec33);
    vector<int>num5={3,6,3,8,9,1,3};
    sort(num5.begin(),num5.end());
    show(num5);
    cout<<"binary serach: "<<binary_search(num5.begin(),num5.end(),3)<<endl;
    cout<<"count: "<<count(num5.begin(),num5.end(),3)<<endl;
    reverse(num5.begin(),num5.begin()+4);
    show(num5);
    random_shuffle(num5.begin(),num5.end());
    show(num5);
    cout<<"Max element: "<<*max_element(num5.begin(),num5.end())<<endl;
    vector<int>num6(4,6);
    vector<int>res1(num5.size()+num6.size());
    sort(num5.begin(),num5.end());
    merge(num5.begin(),num5.end(),num6.begin(),num6.end(),res1.begin());
    show(res1);
    for_each(num5.begin(),num5.end(),print);
    for_each(num5.begin(),num5.end(),add10);
    cout<<endl;
    for_each(num5.begin(),num5.end(),print);
    cout<<count_if(num5.begin(),num5.end(),isEven)<<endl;
    vector<int> num3 ={2, -6, 7, 3, 0, 8, -9, -2};
    for_each(num3.begin(),num3.end(),print);
    int howMany = count_if(num3.begin(),num3.end(),bind2nd(greater<int>(),0));
    cout<<endl<<"Wersja1: wartosc>0 "<<howMany<<endl;
    greater<int> f;
    howMany = count_if(num3.begin(),num3.end(),bind2nd(f,0));
    cout<<"wersja2: wartosc > 0 "<<howMany<<endl;
    cout<<"Przed sortowaniem"<<endl;
    for_each(num3.begin(),num3.end(),print);
    sort(num3.begin(),num3.end(),greater<int>());
    cout<<"Po sortowaniu"<<endl;
    for_each(num3.begin(),num3.end(),print);
    for_each(num3.begin(),num3.end(),print);
    cout<<endl;
    cout<<count_if(num3.begin(),num3.end(),isEven);
    cout<<count_if(num3.begin(),num3.end(),Even(2));
    vector<Student<int>>st;
    st.push_back(Student<int>(1,"Ala"));
    st.push_back(Student<int>(5,"Ola"));
    st.push_back(Student<int>(2,"Piotr"));
    cout<<endl;
    for_each(st.begin(),st.end(),showMark<int>);
    cout<<endl;
    sort(st.begin(),st.end(),Compare());
    for_each(st.begin(),st.end(),showMark<int>);

    //lab5 kontenery asocjacyjne
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(3);
    show(s);
    s.erase(s.begin(),s.find(2));
    show(s);
    s.erase(2);
    cout<<s.count(2)<<endl;
    set<int>zbior1={1,2,3,7};
    set<int>zbior2={-2,4,1,7,6};
    set<int>sUnion;
    set<int>sIntersec;
    set<int>sDiffer;
    set_union(zbior1.begin(),zbior1.end(),zbior2.begin(),zbior2.end(),insert_iterator(sUnion,sUnion.begin()));
    set_intersection(zbior1.begin(),zbior1.end(),zbior2.begin(),zbior2.end(),insert_iterator(sIntersec,sIntersec.begin()));
    set_difference(zbior1.begin(),zbior1.end(),zbior2.begin(),zbior2.end(),insert_iterator(sDiffer,sDiffer.begin()));
    cout<<"Sunion: ";
    showSet(sUnion);
    cout<<"sIntersec: ";
    showSet(sIntersec);
    cout<<"sDiffer: ";
    showSet(sDiffer);

    cout<<endl;
    set<int> s3={3,7};
    pair<set<int>::iterator, bool> res5;
    res5 = s3.insert(6);
    cout<<"Dodany element: "<<*(res5.first)<<endl;
    cout<<"Czy element dodany?: "<<res5.second<<endl;
    //map
    map<string,int> m;
    m.insert(make_pair("robie",10));
    m.insert(pair<string,int>("jan",10000));
    m["jakubczyk"]=50;
    showMap(m);
    cout<<"jakubczyk: "<<m["jakubczyk"]<<endl;
    m.erase("jakubczyk");
    cout<<"Ile jest jakubczykow: "<<m.count("jakubczyk")<<endl;
    pair<string,int> el=*m.begin();
    cout<<"Klucz: "<<el.first<<" "<<"war: "<<el.second<<endl;
    map<string,int>::iterator znaleziony = searchByValue(m,10);
    cout<<endl;
    showMap(m);
    cout<<endl;
    m.erase(znaleziony);
    showMap(m);

    //lab6 BOOST
    person_multi persons;
    persons.insert({"Ala",40});
    persons.insert({"Piotr",10});
    persons.insert({"Ola",18});
    persons.insert({"Ala",46});
    persons.insert({"Ula",46});

    cout<<"Liczba osob o imieniu Ala:"<<persons.count("Ala")<<endl;
    cout<<"Liczba osob o imieniu Ala:"<<persons.get<0>().count("Ala")<<endl;
    age_type &age_index = persons.get<1>();
    cout<<"Liczba osob z wiekiem 18 lat: "<<age_index.count(18)<<endl;
    for(name_type::iterator it=persons.get<0>().begin();it!=persons.get<0>().end(); ++it) {
        it->show();
    }
    auto &age_indexx = persons.get<1>();
    auto it = age_indexx.find(46);
    cout<<"Znaleziona osoba, ktora ma 46 lat "<<it->name<<endl;
    auto &name_indexx = persons.get<0>();
    auto itt = name_indexx.find("Ula");
    name_indexx.modify(itt,boost::bind(UlaToUrszula, _1));
    cout<<"Przed modyfikacją"<<endl;
    vector<name_type::iterator>elements;
    for(name_type::iterator it=persons.get<0>().begin();it!=persons.get<0>().end();++it) {
        it->show();
        elements.push_back(it);
    }
    for(int i=0;i<elements.size();i++) {
        name_indexx.modify(elements[i],boost::bind(AlaToAlicja,_1));
    }
    cout<<"Po modyfikacji: "<<endl;
    for(name_type::iterator it=persons.get<0>().begin();it!=persons.get<0>().end();++it) {
        it->show();
    }
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

    return 0;
}
