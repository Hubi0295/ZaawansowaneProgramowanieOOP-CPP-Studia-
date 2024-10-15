

#include "Employee.h"

Employee::Employee(string surname1,int age1,int experience1,float salary1){
    surname=surname1;
    age=age1;
    experience=experience1;
    salary=salary1;
    cout<<"Konstruktor klasy bazowej employeee"<<endl;
}
Employee::Employee(){
    cout<<"Konstruktor klasy employeee"<<endl;
}
Employee::~Employee(){
    cout<<"Wirtualny destruktor klasy bazowej Employee"<<endl;
}
void Employee::show(){
    cout<<"Surname: "<<surname<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Experience: "<<experience<<endl;
    cout<<"Salary: "<<salary<<endl;
}
int Employee::ageEmployment(){
    return age-experience;
}
string Employee::getSurname(){
    return surname;
}
int Employee::getAge(){
    return age;
}
int Employee::getExperience(){
    return experience;
}
float Employee::getSalary(){
    return salary;
}
void Employee::whoWorkMoreThan5Years(Employee **tab, int size) {
    for(int i=0;i<size;i++) {
        if(tab[i]->getExperience()>5) {
            cout<<"Mam wieksze doswiadczenie niż 5 lat"<<endl;
            tab[i]->show();
        }
    }
}
void Employee::howManyEarnLessThanMeanBonus(Employee **tab, int size) {
    float mean=0;
    for(int i=0;i<size;i++) {
        mean+=tab[i]->getSalary();
    }
    mean /= size;
    int counter=0;
    for(int i=0;i<size;i++) {
        if(tab[i]->getSalary()<mean) {
            counter++;
        }
    }
    cout<<"Liczba pracownikow ktorzy zarabiaja mniej niz srednia wynosi: "<<counter<<endl;
}
