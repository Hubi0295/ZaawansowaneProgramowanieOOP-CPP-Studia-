//
// Created by Hubert on 11.12.2024.
//

#include "Circle.h"

Circle::Circle(float r1) {
    r=r1;
    cout<<"Konstruktor klasy Circle"<<endl;
}

Circle::~Circle() {
    cout<<"Destruktor klasy Circle"<<endl;
}

void Circle::calculateArea() {
    setArea(3.14*r*r);
}
