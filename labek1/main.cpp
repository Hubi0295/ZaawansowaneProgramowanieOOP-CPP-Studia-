#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
int main() {
   cout<<endl<<"Obiekty klasy Person"<<endl;
   Person o1("Grazyna","Nowak",45);
   o1.showInfoPerson();
   cout<<"Czy pelnoletnia?: "<<o1.is_18()<<endl;
   o1.setAge(16);
   cout<<endl<<"Obiekty klasy Teacher"<<endl;
   Teacher n1("Barbara","Kowalska",56,30,"Phd");
   n1.showInfoTeacher();
   cout<<"Czy ma Phd?: "<<n1.is_Phd()<<endl;
   n1.setAge(34);

   cout<<endl<<endl;

   Person p1[3];
   Person *p2;
   Person *p3[3];
   Person **p4;
   for(int i=0;i<3;i++) {
      p1[i].init("anna", "nowak", 20+i);
      p1[i].showInfoPerson();
   }

   p2=new Person[3];
   for(int i=0;i<3;i++) {
      p2[i].init("ola", "adamek", 20+i);
      p2[i].showInfoPerson();
   }
   for(int i=0;i<3;i++) {
      p3[i]=new Person("Kasia","kowalska", 20+i);
      p3[i]->showInfoPerson();
   }
   p4=new Person*[3];
   for(int i=0;i<3;i++) {
      p4[i]=new Person("Pawel","wojcik",20+i);
      p4[i]->showInfoPerson();
   }
   for(int i=0;i<3;i++) {
      delete p4[i];
   }
   delete [] p4;
   cout<<endl;
   Student s1[3];
   Student *s2;
   Student *s3[3];
   Student **s4;

   for(int i=0;i<3;i++) {
      s1[i].init("Abelard","Giza", 18+i);
      s1[i].setIndex(to_string(10+i));
      s1[i].showInfoStudent();
   }
   cout<<endl;
   s2=new Student[3];
   for(int i=0;i<3;i++) {
      s2[i].init("Janusz","Palikot", 60+i);
      s2[i].setIndex(to_string(20+i));
      s2[i].showInfoStudent();
   }
   cout<<endl;
   for(int i=0;i<3;i++) {
      s3[i]=new Student("Marek","Janko",33+i,to_string(30+i));
      s3[i]->showInfoStudent();
   }
   cout<<endl;
   s4=new Student*[3];
   for(int i=0;i<3;i++) {
      s4[i]=new Student("Tadeusz","Mazur",100+i,to_string(40+i));
      s4[i]->showInfoStudent();
   }
   for(int i=0;i<3;i++) {
      delete s4[i];
   }
   delete [] s4;
   cout<<endl;

   Animal zwierze(4,"swinka",false);
   zwierze.info();

   Dog dobryPiesek(4,"kajtek",false,"mieszaniec",5,5);


   dobryPiesek.setSkillLevel(0,7);
   dobryPiesek.setSkillLevel(1,9);
   dobryPiesek.info();
   dobryPiesek.giveVoice();

   cout<<endl;
   Cat kotek(4,"kotek",true);
   kotek.initCat(5);
   kotek.info();

   Animal zwierzeta[6];
   zwierzeta[0]=dobryPiesek;
   zwierzeta[1]=dobryPiesek;
   zwierzeta[2]=dobryPiesek;
   zwierzeta[3]=kotek;
   zwierzeta[4]=kotek;
   zwierzeta[5]=zwierze;
   cout<<"liczba zwierzat chronionych: "<<Animal::howManyProtectedAnimals(zwierzeta,6)<<endl;

   cout<<endl<<endl;
   Dog psy[3];
   psy[0]=Dog(4,"kajetk",1,"mieszaniec",3,6);
   psy[1]=Dog(4,"janek",0,"szpic",6,4);
   psy[2]=Dog(4,"tadek",1,"owczarek",3,6);
   Dog::howManyTrackerDogs(psy,3);

   cout<<endl<<endl;
   Cat koty[3];
   koty[0]=Cat(4,"astroidDestroyer1",false);
   koty[0].initCat(9);
   koty[1]=Cat(3,"astroidDestroyer2",true);
   koty[1].initCat(9);
   koty[2]=Cat(2,"astroidDestroyer3",false);
   koty[2].initCat(8);
   Cat::howManyCats(koty,3);



   return 0;
}
