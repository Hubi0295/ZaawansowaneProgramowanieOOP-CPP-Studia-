//
// Created by Hubert on 11.12.2024.
//

#include "Figure.h"

Figure::Figure() {
    cout<<"Konstruktor klasy bazowej Figure"<<endl;
}

Figure::~Figure() {
    cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;

}

float Figure::getArea() {
    return area;
}

void Figure::setArea(float area) {
    this->area=area;
}

void Figure::show() {
    cout<<"Pole: "<<area<<endl;
}
