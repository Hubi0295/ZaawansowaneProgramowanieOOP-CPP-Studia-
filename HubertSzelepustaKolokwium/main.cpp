//C++20
//Hubert Szelepusta 99707
#include <algorithm>
#include <iostream>
#include <map>

#include "FunktorStudenta.h"
#include "Student.h"
#include "subject.h"
int amount_of_fail_subjects(Student<int> &s) {
    map<subject,int> kopiaOcen = s.getOceny();
    int ileOblanych = count_if(kopiaOcen.begin(),kopiaOcen.end(),FunktorStudenta());
    return ileOblanych;
}

int main() {
    subject s(5,"matma","bb",234,5);
    subject s2(3,"polski","bb",234,5);
    subject s3(4,"matma","bb",234,5);
    subject s4(6,"polski","bb",234,5);
    subject s5(8,"matma","bb",234,5);
    subject s6(12,"polski","bb",234,5);
    bool x = s2<s;
    cout<<"s2.id < s.id: "<<x<<endl;

    map<subject,int> mapa;
    mapa[s] = 5;
    mapa[s2] = 4;
    mapa[s3] = 1;//oblana
    mapa[s4] = 1;//oblana
    mapa[s5] = 1;//oblana
    mapa[s6] = 3;
    Student<int>studencik("janek","pawlowski",4,mapa);
    studencik.show_all_grades();

    map<subject,string> mapa2;
    mapa2[s] = "bardzo dobra";
    mapa2[s] = "bardzo dobra";//dobrze działa nie powtarza sie dla tego samego subjectu
    mapa2[s2] = "dobra";
    Student<string>studencik2("janek","pawlowski",4,mapa2);
    studencik2.show_all_grades();

    int oblane = amount_of_fail_subjects(studencik);
    cout<<"Liczba oblanych przedmiotow przez Studencika: "<<oblane<<endl;

    return 0;
}
