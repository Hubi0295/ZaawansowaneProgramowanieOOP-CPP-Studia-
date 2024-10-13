//
// Created by Daniel on 2024-10-13.
//
#include <iostream>
#include "meanBufor.h"
using namespace std;
meanBufor::meanBufor() {
    cout<<"Konstruktor bez arguemntow -meanBufor"<<endl;
}
meanBufor::meanBufor(int size):Bufor(size) {
    cout<<"Konstruktor z arguemntami -meanBufor"<<endl;

}
meanBufor::~meanBufor() {
    cout<<"destruktor -meanBufor"<<endl;

}
double meanBufor::calculate() {
    double sum = 0;
    for(int i=0;i<getIndex();i++) {
        sum+=getTab(i);
    }
    return sum/getIndex();
}
