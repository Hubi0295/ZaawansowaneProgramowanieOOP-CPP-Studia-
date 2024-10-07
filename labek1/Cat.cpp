//
// Created by Hubert on 07.10.2024.
//

#include "Cat.h"
#include <iostream>
using namespace std;
Cat::Cat(int limbs1,string name1,bool is_protected1):Animal(limbs1,name1,is_protected1){}
Cat::Cat(){
}
void Cat::initCat(int levelOfMouseHunting1){
    if(levelOfMouseHunting1>0&&levelOfMouseHunting1<=10) {
        levelOfMouseHunting=levelOfMouseHunting1;
    }
    else {
        do {
            cout<<"Zla wartosc podaj nowa z zakresu <1,10>: ";
            cin>>levelOfMouseHunting1;
        }while(levelOfMouseHunting1<=0||levelOfMouseHunting1>10);
        levelOfMouseHunting=levelOfMouseHunting1;
    }
    mice=new int[5];
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
    levelOfMouseHunting=value;
}
int Cat::getMice(int index){
    return mice[index];
}
void Cat::giveVoice(){
    cout<<"Miau miau"<<endl;
}
void Cat::info(){
    cout<<"limbs: "<<getLimb_nr()<<
    "name: "<<getName()<<" isProtected"<<getIs_protected_animal()<<
    " levelOfMouseHunting: "<<levelOfMouseHunting<<
    " mice: "<<endl;
    for(int i=0;i<5;i++) {
    cout<<i+1<<" "<<mice[i]<<endl;
    }
}
int Cat::howManyCats(Cat a[],int length) {
    int num=0;
    for(int i=0;i<length;i++) {
        for(int j=0;j<5;j++) {
            num+=a[i].mice[j];
        }
    }
    return num;
}