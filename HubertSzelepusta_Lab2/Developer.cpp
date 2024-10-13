//
// Created by Daniel on 2024-10-12.
//

#include "Developer.h"
#include "Employee.h"
Developer::Developer(string surname1, int age1, int experience1, float salary1):
    Employee(surname1,age1,experience1,salary1){
    cout<<"Konstruktor klasy pochodnej- Developer"<<endl;
}
Developer::Developer(){
    cout<<"Konstrukto klasy Developer"<<endl;
}
Developer::~Developer(){
    cout<<"Destruktor klasy Developer"<<endl;
}
int Developer::calculateBonus(int value){
    return value+0.2*value*(getSalary()+getExperience());
}

