#include "Cat.h"
#include <iostream>
using namespace std;
Cat::Cat(int limbs1,string name1,bool is_protected1):Animal(limbs1,name1,is_protected1){}
Cat::Cat(){
}
void Cat::initCat(int levelOfMouseHunting1){

    while(levelOfMouseHunting1<=0||levelOfMouseHunting1>10){
        cout<<"Zla wartosc podaj nowa z zakresu <1,10>: ";
        cin>>levelOfMouseHunting1;
    }
    levelOfMouseHunting=levelOfMouseHunting1;
    mice=new int[5];
    this->initMice();
}
void Cat::initMice(){
    for(int i=0;i<5;i++) {
        cout<<"Podaj wartosc dla roku nr: "<<i+1<<endl;
        cin>>mice[i];
    }
}
int Cat::getLevelOfMouseHunting(){
    return levelOfMouseHunting;
}
void Cat::setLevelOfMouseHunting(int value){
    while(value<=0||value>10){
        cout<<"Zla wartosc podaj nowa z zakresu <1,10>: ";
        cin>>value;
    }
    levelOfMouseHunting=value;
}
int Cat::getMice(int index){
    return mice[index];
}
void Cat::giveVoice(){
    cout<<"Miau miau"<<endl;
}
void Cat::info(){
    cout<<"limbs: "<<getLimbNr()<<
    "name: "<<getName()<<" isProtected"<<getProtected_animal()<<
    " levelOfMouseHunting: "<<levelOfMouseHunting<<
    " mice: "<<endl;
    for(int i=0;i<5;i++) {
    cout<<i+1<<" "<<mice[i]<<endl;
    }
}
void Cat::howManyCats(Cat a[],int length) {
    int num=0;
    for(int i=0;i<length;i++) {
        for(int j=0;j<5;j++) {
            num+=a[i].mice[j];
        }
        cout<<"Liczba upolowanych myszy przez: "<<a[i].getName()<<": "<<num<<endl;
        num = 0;
    }
}