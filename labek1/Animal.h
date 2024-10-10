#ifndef ANIMAL_H
#define ANIMAL_H


#include <iostream>
using namespace std;
class Animal {
private:
    int limbNr;
    string name;
    bool protectedAnimal;
public:
    Animal();
    Animal(int limbNr1, string Name1, bool protectedAnimal1=true);
    int getLimbNr();
    void setLimbNr(int limb_nr1);
    string getName();
    void setName(string name1);
    bool getProtected_animal();
    void setProtected_animal(bool protected_animal);
    void giveVoice();
    void info();
    static int howManyProtectedAnimals (Animal a[], int length);
};



#endif //ANIMAL_H
