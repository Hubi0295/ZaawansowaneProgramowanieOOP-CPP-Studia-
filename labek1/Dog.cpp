//
// Created by Daniel on 2024-10-07.
//

#include "Dog.h"
using namespace std;
Dog::Dog() {
    cout << "Konstruktor bez klasy bazowej Bez arg- Dog" << endl;
}
Dog::Dog(int limbnr1,string name1,bool isProtected, string breed1,int levelOfGuideSkills1,int levelOfTrackerSkills1)
    :Animal(limbnr1,name1,isProtected){
    breed=breed1;
    levelOfGuideSkills=levelOfGuideSkills1;
    levelOfTrackerSkills = levelOfTrackerSkills1;
    cout<<"Konstruktor klasy bazowej -Dog"<<endl;
}
Dog::Dog(string breed1,int levelOfGuideSkills1,int levelOfTrackerSkills1) {
    breed=breed1;
    levelOfGuideSkills=levelOfGuideSkills1;
    levelOfTrackerSkills = levelOfTrackerSkills1;
    cout << "Konstruktor bez klasy bazowej z arg- Dog" << endl;
}
void Dog::setSkillLevel(int type, int value) {
    if(value>=1 && value<=10) {
        if(type==0) {
            levelOfGuideSkills=value;
        }
        else if(type==1) {
            levelOfTrackerSkills=value;
        }
        else {
            cout<<"Zły podany typ"<<endl;
        }
    }

    cout<<"Zła podana wartosc"<<endl;

}
int Dog::getSkillLevel(int type) {
    if(type==0) {
        if(levelOfGuideSkills==0) {
            return 0;
        }
        return  levelOfGuideSkills;
    }
    else if(type==1) {
        if(levelOfTrackerSkills==0) {
            return 0;
        }
        return levelOfTrackerSkills;
    }
    else {
        cout<<"Zły podany typ"<<endl;
        return 0;
    }
}
void Dog::getVoice() {
    cout<<"Hau Hau"<<endl;
}
void Dog::info() {
    cout<<" limbnr"<<getLimb_nr()<<" name: "<<getName()<<" isProtected"<<getIs_protected_animal()<<" breed: "<<breed<<" LevelOfGuideSkills:"<<levelOfGuideSkills<<" LevelOfTrackerSkills"<<levelOfTrackerSkills<<endl;
}