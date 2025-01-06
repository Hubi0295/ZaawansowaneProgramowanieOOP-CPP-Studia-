//
// Created by Hubert on 18.10.2024.
//

#ifndef ADDING_H
#define ADDING_H
#include <iostream>
#include <ostream>

using namespace std;
template<typename T>
class Adding {
private:
    T element ;
public:
    Adding(T value);
    void add(T value);
    void show();
};
template<typename T>
Adding<T>::Adding(T value) {
    element = value;
}
template<typename T>
void Adding<T>::add(T value) {
    element += value;
}
template<>
void Adding<string>::add(string value) {
    element+=value;
    cout<<"Dodaj stringa"<<endl;
}
template<typename T>
void Adding<T>::show() {
    cout<<"Element: "<<element<<endl;
}
template <typename T>
void showAll(T *tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i]->show();
    }
}




#endif //ADDING_H
