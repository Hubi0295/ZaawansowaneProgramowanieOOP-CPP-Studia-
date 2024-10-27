//
// Created by Daniel on 2024-10-27.
//

#include "City.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <ostream>


City::City()
{
}
City::City(string city_name)
{
    this->city_name = city_name;
}
void City::addCitizen(Citizen c)
{
    this->citizens.push_back(c);
}
void City::deleteCitizen(string surname,int age)
{
    for(int i=0;i<citizens.size();i++) {
        if(citizens[i].get_surname() == surname && citizens[i].get_age() == age) {
            cout<<"Jest"<<endl;
            citizens.erase(citizens.begin()+i);
        }
    }
}
void City::show_citizens()
{
    for(int i=0;i<citizens.size();i++) {
        Citizen::show(citizens[i]);
    }
}
void City::show_city()
{
    cout<<"City name: "<<city_name<<endl;
}
bool isWomen(Citizen c){
    return c.get_sex()=='W';
}
int  City::women()
{
    return count_if(citizens.begin(),citizens.end(),isWomen);
}
int  City::city_citizens()
{
    return citizens.size();
}
bool isAdult(Citizen c) {
    return c.get_age()>=18;
}
int  City::adults()
{
    return count_if(citizens.begin(),citizens.end(),isAdult);
}
