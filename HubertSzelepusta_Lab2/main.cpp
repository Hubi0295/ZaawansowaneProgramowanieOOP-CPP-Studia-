#include <iostream>
#include "figure.h"
#include "square.h"
#include "circle.h"
#include "employee.h"
#include "developer.h"
#include "teamleader.h"
#include "meanBufor.h"
#include "maxBufor.h"
using namespace std;
int main() {
    // Figure *f1 = new Square(4);
    // Figure *f2 = new Circle(2);
    // f1->calculateArea();
    // f1->show();
    //
    // f2->calculateArea();
    // f2->show();
    //
    // delete f1;
    // delete f2;
    //
    // Figure *f3;
    // Square s1(4);
    // f3=&s1;
    // f3->calculateArea();
    // f3->show();
    // cout<<endl<<endl;
    // Figure *tab[3];
    // tab[0]=new Square(4);
    // tab[1]=new Square(2);
    // tab[2]=new Circle(5);
    // for(int i=0;i<3;i++){
    //     tab[i]->calculateArea();
    //     tab[i]->show();
    //     tab[i]->calculateCircuit();
    //     delete tab[i];
    // }
    Developer d1("jacek",56,36,34000.01);
    d1.show();
    Developer d2("marek",25,3,10000.25);
    d2.show();
    TeamLeader t1("darek",30,7,15000.25);
    t1.show();
    Employee **tab;
    tab = new Employee *[3];
    tab[0] = &d1;
    tab[1] = &d2;
    tab[2] = &t1;
    Employee::whoWorkMoreThan5Years(tab,3);
    Employee::howManyEarnLessThanMeanBonus(tab,3);

    meanBufor m(10);
    cout<<m.getIndex()<<endl;
    m.add(15);
    m.add(20);
    m.add(30);
    m.add(40);
    m.add(50);
    m.show();
    cout<<"Sredni z liczb: "<<m.calculate()<<endl;

    maxBufor m1(10);
    m1.add(15);
    m1.add(20);
    m1.add(30);
    m1.add(40);
    m1.add(50);
    m1.show();
    cout<<"Największa: "<<m1.calculate()<<endl;
    return 0;
}
