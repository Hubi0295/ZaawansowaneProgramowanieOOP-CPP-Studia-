//
// Created by Daniel on 2024-10-12.
//

#include "Circle.h"
#include "Figure.h"
#include <iostream>
using namespace std;
Circle::Circle(float r1)
{
    r=r1;
    cout<<"Konstruktor w klasie Circle"<<endl;
}

Circle::~Circle()
{
    cout<<"Destruktor w klasie Circle"<<endl;
}
void Circle:: calculateArea(){
    setArea(3.14*r*r);
}
void Circle::calculateCircuit(){
    cout<<"Obwod kola: "<<2*3.14*r<<endl;
}
