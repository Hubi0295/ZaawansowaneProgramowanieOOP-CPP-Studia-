//
// Created by Hubert on 06.01.2025.
//

#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
using namespace std;
class Car {
private:
    std::string model;
    int rok_prod;
    float poj_silnika;
public:
    Car();
    Car(string model,int rok_prod, float poj_silnika);

    std::string get_model() const;

    int get_rok_prod() const;

    float get_poj_silnika() const ;

    void set_model(std::string model);

    void set_rok_prod(int rok_prod);

    void set_poj_silnika(float poj_silnika);
    void show();
};



#endif //CAR_H
