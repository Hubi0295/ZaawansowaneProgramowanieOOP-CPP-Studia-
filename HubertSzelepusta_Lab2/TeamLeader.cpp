

#include "TeamLeader.h"
#include "Employee.h"
#include <iostream>
using namespace std;
TeamLeader::TeamLeader(string surname1,int age1, int experience1,float salary1):Employee(surname1,age1,experience1,salary1) {
    cout<<"Konstruktor klasy pochodnej Team Leader"<<endl;
}
TeamLeader::TeamLeader() {
    cout<<"Konstruktor bezargumentowy Team Leader"<<endl;
}
TeamLeader::~TeamLeader() {
    cout<<"Destruktor klasy TeamLeader"<<endl;
}
int TeamLeader::calculateBonus(int value){
    return value*(1+getSalary()+getExperience());
}
void TeamLeader::show(){
    cout<<"Surname: "<<getSurname()<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Experience: "<<getExperience()<<endl;
    cout<<"Salary: "<<getSalary()<<endl;
    cout<<"Jestem team leaderem z "<<getExperience()<<" stażem"<<endl;
}
