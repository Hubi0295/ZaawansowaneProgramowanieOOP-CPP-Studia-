//
// Created by Daniel on 2024-10-13.
//

#include "maxBufor.h"
#include <iostream>
using namespace std;
maxBufor::maxBufor(){
    cout<<"Konstruktor bez arguemntow -maxBufor"<<endl;

}
maxBufor::maxBufor(int size):Bufor(size){
    cout<<"Konstruktor z arguemntami -maxBufor"<<endl;

}
maxBufor::~maxBufor(){
    cout<<"Destruktor  -maxBufor"<<endl;

}
double maxBufor::calculate(){
    double num = getTab(0);
    for(int i=0;i<getIndex();i++) {
        if(getTab(i)>num) {
            num = getTab(i);
        }
    }
    return num;
}
void maxBufor::add(int value){
    if(getIndex()==getSize()-1) {
        cout<<"niestety nie ma juz miejsca w tablicy"<<endl;
    }
    else {
        setTab(getIndex(), value);
        incrementIndex();
    }
}