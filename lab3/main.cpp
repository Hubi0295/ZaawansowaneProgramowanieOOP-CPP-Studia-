#include <iostream>
#include "Adding.h"
#include "Student.h"
#include "Array.h"
using namespace std;
template <typename T>
T funkcja(T a[], int b) {
    T minimal = a[0];
    for(int i=0;i<b;i++) {
        if(a[i] < minimal) {
        minimal = a[i];
        }
    }
    return minimal;
}
template<typename  T>
void checkType(T a)
{
    cout<<std::numeric_limits<T>::max()<<endl;
}

template<typename  T>
void mySwap(T &a, T &b) {
    T temp = a;
    temp = a;
    a=b;
    b = temp;
}

int main(){
    std::cout << "Hello, World!" << std::endl;
    int a =10;
    std::cout << a << std::endl;
    int b=20;
    std::cout << b << std::endl;
    mySwap<int>(a,b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;


    Adding<int> a1(5);
    a1.add(6);
    a1.show();
    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();

    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();

    Adding<int> *arrAdd[3];
    for(int i=0;i<3;i++) {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);

    Student<string> *arrStu[2];
    for(int i=0;i<3;i++) {
        arrStu[i]=new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);
    for(int i=0;i<3;i++) {
        delete arrAdd[i];
    }
    for(int i=0;i<2;i++) {
        delete arrStu[i];
    }
    // double xx=3.0;
    // checkType<double>(xx);

    int x[]={1,2,3,4,5,6,-100,-200,500,600,700,800,-1000};
    cout<<funkcja(x,13)<<endl;

    Array<int>nowa(15);
    for(int i=0;i<15;i++) {
        int x = rand()%100;
        cout<<"Wylosowano: "<<x<<endl;
        nowa.add(x);
    }
    nowa.sortIt();
    nowa.show();
    cout<<"Max: "<<nowa.getMax()<<endl;
    Array<string>nowa2(15);
    string s10="liczba";
    for(int i=0;i<15;i++) {
        nowa2.add(s10+to_string(rand()%11000));
    }
    nowa2.sortIt();
    nowa2.show();
    cout<<"Max: "<<nowa2.getMax()<<endl;
    return 0;
}

