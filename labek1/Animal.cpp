//
// Created by Daniel on 2024-10-07.
//

#include "Animal.h"
Animal::Animal() {
    cout<<"Konstruktor bez klasy bazowej Animal"<<endl;
}
Animal::Animal(int limbNr1, string Name1, bool protectedAnimal1) {
    limbNr=limbNr1;
    name = Name1;
    protectedAnimal = protectedAnimal1;
}



int Animal::getLimb_nr(){
    return limbNr;
}

void Animal::setLimb_nr(int limb_nr1) {
    limbNr = limb_nr1;
}

string Animal::getName() {
    return name;
}

void Animal::setName(string name1) {
    name = name1;
}

bool Animal::getIs_protected_animal() {
    return protectedAnimal;
}

void Animal::SetIs_protected_animal(bool protected_animal) {
    protectedAnimal = protected_animal;
}
void Animal::getVoice() {
    cout<<"Chrum, miau, hau, piiiii"<<endl;
}
void Animal::info() {
    cout<<"Limb_nr: "<<limbNr<<"; Name: "<<name<<" Protected: "<<protectedAnimal<<endl;
}

