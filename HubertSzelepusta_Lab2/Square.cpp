
#include "Square.h"
#include <iostream>
#include "Figure.h"
using namespace std;

Square::Square(float a1):Figure()
{
    a=a1;
    cout<<"Konstruktor klasy Square"<<endl;
}

Square::~Square()
{
    cout<<"destruktor klasy Square"<<endl;
}
void Square::calculateArea(){
    setArea(a*a);
}
void Square::show()
{
    cout<<"Show w klasie Square, pole: "<<getArea()<<endl;
}
void Square::calculateCircuit(){
    cout<<"Obwod kwadratu: "<<4*a<<endl;
}
