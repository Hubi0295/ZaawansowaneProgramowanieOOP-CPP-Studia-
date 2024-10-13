#include "Bufor.h"
#include <iostream>
using namespace std;
Bufor::Bufor(){
    pointer = new int[10];
    index=0;
    size=10;
    cout<<"Konstruktor bezargumentow -bufor"<<endl;
}
Bufor::Bufor(int size1){
    pointer = new int[size1];
    index=0;
    size=size1;
    cout<<"Konstruktor z arguemntami -bufor"<<endl;
}
Bufor::~Bufor(){
    cout<<"Destruktor virtualny-bufor"<<endl;

}
void Bufor::add(int value){
    pointer[index]=value;
    index++;
}
int Bufor::getSize(){
    return size;
}
int Bufor::getIndex(){
    return index;
}
int Bufor::getTab(int i){
    return pointer[i];
}
int Bufor::getFirst(){
    return index+1;
}
void Bufor::setFirst(int value){
    pointer[index]=value;
}
void Bufor::setTab(int pos, int value){
    pointer[pos]=value;
}
void Bufor::incrementIndex() {
    index++;
}
void Bufor::show(){
    for(int i=0;i<getIndex();i++) {
        cout<<"i:"<<pointer[i]<<endl;
    }
}
