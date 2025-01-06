//
// Created by Hubert on 11.12.2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
template<typename T>
class Student{
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark=mark;
        this->name=name;
    }
    Student(){};
    void show() {
        cout<<"Imie: "<<name<<" ocena: "<<mark<<endl;
    }
    void showMark();
    int getMark() {
        return mark;
    }
};
template<>
class Student<string> {
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark = mark;
        this->name=name;
    }
    Student(){};
    void show() {
        cout<<"String imie: "<<name<<" ocena: "<<mark<<endl;
    }
    int showMark() {
        string word [6] = {"jedynka","dwojka","trojka","czworka","piatka","szostka"};
        cout<<"Twoja ocena to: "<<word[mark-1]<<endl;
        return mark;
    }
    int getMark() {
        return mark;
    }
};
#endif //STUDENT_H
