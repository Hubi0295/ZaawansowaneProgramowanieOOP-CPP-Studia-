//
// Created by Hubert on 18.10.2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <ostream>
using namespace std;

template <typename T>
class Student {
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark = mark;
        this->name = name;
    }
    Student() {

    }
    void show() {
        cout<<"Imię: "<<name<<endl<<" Ocena"<<mark<<endl;
    }
    void showMark() {
        cout<<mark<<endl;
    }
};
template<>
void Student<int>::showMark() {
    cout<<"Twoja ocena: "<<mark<<endl;
}
template<>
class Student<string> {
private:
    string name;
    int mark;
public:
    Student(int mark, string name) {
        this->mark = mark;
        this->name = name;
    }
    Student();
    void show() {
        cout<<"imie: "<<name<<" ocena"<<mark<<endl;
    }
    int showMark() {
        string word[6]={"jedynka","dwojka","trojka","czworka","piatka","szostka"};
        cout<<"Twoja ocena: "<<word[mark-1]<<endl;
        return mark;
    }
};



#endif //STUDENT_H
