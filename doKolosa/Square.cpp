//
// Created by Hubert on 11.12.2024.
//

#include "Square.h"

Square::Square(float a1) {
    a=a1;
    cout<<"Konstruktor klasy Square"<<endl;

}

Square::~Square() {
    cout<<"Destruktor klasy Square"<<endl;

}

void Square::calculateArea() {
    setArea(a*a);
}
void Square::show() {
    cout<<"Show w klasie Square, pole: "<<getArea()<<endl;
}

