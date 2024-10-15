

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;
class Employee
{
private:
    string surname;
    int age;
    int experience;
    float salary;
public:
    Employee(string surname1,int age1,int experience1,float salary1);
    Employee();
    virtual ~Employee();
    virtual void show();
    virtual int calculateBonus(int value)=0;
    int ageEmployment();
    string getSurname();
    int getAge();
    int getExperience();
    float getSalary();
    static void whoWorkMoreThan5Years(Employee **tab, int size);
    static void howManyEarnLessThanMeanBonus(Employee **tab, int size);
};




#endif //EMPLOYEE_H
