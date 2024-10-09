#include "Animal.h"
Animal::Animal() {
    cout<<"Konstruktor bez klasy bazowej Animal"<<endl;
}
Animal::Animal(int limbNr1, string Name1, bool protectedAnimal1) {
    limbNr=limbNr1;
    name = Name1;
    protectedAnimal = protectedAnimal1;
}



int Animal::getLimbNr(){
    return limbNr;
}

void Animal::setLimbNr(int limb_nr1) {
    limbNr = limb_nr1;
}

string Animal::getName() {
    return name;
}

void Animal::setName(string name1) {
    name = name1;
}

bool Animal::getProtected_animal() {
    return protectedAnimal;
}

void Animal::SetProtected_animal(bool protected_animal) {
    protectedAnimal = protected_animal;
}
void Animal::giveVoice() {
    cout<<"Chrum, miau, hau, piiiii"<<endl;
}
void Animal::info() {
    cout<<"Limb_nr: "<<limbNr<<"; Name: "<<name<<" Protected: "<<protectedAnimal<<endl;
}
int Animal::howManyProtectedAnimals(Animal a[], int length) {
    int num=0;
    for(int i=0;i<length;i++) {
        if(a[i].getProtected_animal()) {
            num++;
        }
    }
    return num;
}

