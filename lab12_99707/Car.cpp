//
// Created by Hubert on 06.01.2025.
//

#include "Car.h"
Car::Car() {

}

Car::Car(string model, int rok_prod, float poj_silnika) {
    this->model=model;
    this->rok_prod=rok_prod;
    this->poj_silnika=poj_silnika;
}

std::string Car::get_model() const {
    return model;
}

int Car::get_rok_prod() const{
    return rok_prod;
}

float Car::get_poj_silnika() const{
    return poj_silnika;
}

void Car::set_model(std::string model) {
    this->model = model;
}

void Car::set_rok_prod(int rok_prod) {
    this->rok_prod = rok_prod;
}

void Car::set_poj_silnika(float poj_silnika) {
    this->poj_silnika = poj_silnika;
}
void Car::show() {
    cout<<"Model: "<<model<<endl;
    cout<<"Rok produkcji: "<<rok_prod<<endl;
    cout<<"Pojemnosc: "<<poj_silnika<<endl;
}
