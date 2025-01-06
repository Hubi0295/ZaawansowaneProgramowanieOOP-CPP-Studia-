#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <functional>

#include "Car.h"
using namespace std;
bool fn( int l, int r )
{
return l > r;
}
void printVec(vector< int > num)
{
    cout<<endl<<"Zawartosc num: ";
    for( auto it = num.begin(); it != num.end(); ++it )
        cout << *it << " ";
    cout<<endl;
}
void fun( function < int(int)> f, int n )
{
    for( int i = 0; i < n; ++i )
    cout << "f(" << i << ") = " << f(i) <<endl;
}
tuple<int,float,string> zad12_3(vector<string> napisy) {
    int dlugosc_najkrotszego=napisy[0].length();
    float srednia_dlugosc=0;
    string najdluzszy_napis;
    for_each(napisy.begin(),napisy.end(),[&dlugosc_najkrotszego](string x){if(x.length()<dlugosc_najkrotszego){dlugosc_najkrotszego=x.length();}});
    for_each(napisy.begin(),napisy.end(),[&srednia_dlugosc](string x){srednia_dlugosc+=x.length();});
    srednia_dlugosc /= napisy.size();
    najdluzszy_napis= *max_element(napisy.begin(),napisy.end(),[](string x, string y){return x.length()<y.length();});
    return make_tuple(dlugosc_najkrotszego,srednia_dlugosc,najdluzszy_napis);
}
int main()
{
    tuple <char, int, float> t1;
    t1 = make_tuple('a', 8, 21.5);
    cout << "Liczba elementow: "
    << tuple_size<decltype(t1)>::value << endl;
    cout <<"get<0>: "<< get <0>(t1) << endl;
    cout <<"get<1>: "<< get <1>(t1) << endl;
    cout <<"get<2>: "<< get <2>(t1) << endl;
    tuple_element<0,decltype(t1)>::type first = get<0>(t1);
    tuple_element<1,decltype(t1)>::type second = get<1>(t1);
    cout << "Pierwszy element t1: " << first << endl;
    cout << "drugi element t1: " << second << endl;
    cout<<"Przed modyfikacja: get<1>: "
    <<get<1>(t1)<<endl;
    get<1>(t1)=2;
    cout<<"Po modyfikacji: get<1>: "<<get<1>(t1)<<endl;
    tuple <char,int,float> t2('p',45,7.5);
    cout<<"Przed swap t2"<<endl;
    cout <<"get<0>: "<< get <0>(t2) << endl;
    cout <<"get<1>: "<< get <1>(t2) << endl;
    cout <<"get<2>: "<< get <2>(t2) << endl;
    t2.swap(t1);
    cout<<"Po swap t2"<<endl;
    cout <<"get<0>: "<< get <0>(t2) << endl;
    cout <<"get<1>: "<< get <1>(t2) << endl;
    cout <<"get<2>: "<< get <2>(t2) << endl;
    tuple <int,char> t3(2,'a');
    auto t4=make_tuple(3,'b');
    auto t5 = tuple_cat(t3,t4);
    cout<<"Zawartosc t5: "<<endl;
    cout<<get<0>(t5)<<" "<<get<1>(t5)<<" "<<get<2>(t5)
    <<" "<<get<3>(t5)<<endl;
    int i_val;
    char ch_val;
    float f_val;
    tuple <int,char,float> t6(2,'R',3.5);
    tie(i_val,ch_val,f_val) = t6;
    cout << "Pobranie wszystkich zmiennych z tupli: ";
    cout << i_val << " " << ch_val << " " << f_val<<endl;
    tie(i_val,ignore,f_val) = t6;
    cout << "Pobranie wybranych zmiennych z tupli: ";
    cout << i_val << " " << f_val<<endl;

    vector < int > num= {1,2,3,4,5,6,7,8,9};
    sort(num.begin(),num.end(), fn );
    sort(num.begin(),num.end(),[]( int l, int r )->bool { return l > r ;});
    sort(num.begin(),num.end(),[]( int l, int r ){ return l > r ;});
    printVec(num);
    transform(num.begin(),num.end(),num.begin(),[](int el){ return el*2;});
    cout<<"Zawartosc num: ";
    for_each(num.begin(),num.end(),[](int el){cout<<"**"<<el;});
    for_each(num.begin(),num.end(),[](int&el){el=el*2;});
    printVec(num);

    int sum=0;
    for_each(num.begin(),num.end(),[&sum](int el){sum+=el;});
    cout<<"Suma to: "<<sum<<endl;
    int val=20;
    sum=0;
    for_each(num.begin(),num.end(),[&sum,val](int el){if(el<val) sum+=el;});
    cout<<"Suma el<20 to: "<<sum<<endl;

    cout<<"Suma a+b: "<<[]( int a, int b ) { return a + b;}( 1, 8 )<<endl;
    auto lam=[](int a)->float { if( a > 0 ) return 1;
    return -1.0; };
    cout<<lam(2)<<endl;

    fun([]( int x ) { return x+2; }, 5);

    //zad1
    vector<int> vec = {1,5,4,2,-10,-6,10,12,-9};
    for_each(vec.begin(), vec.end(),[](int x){cout<<x<<"|";});
    float srednia =0;
    for_each(vec.begin(),vec.end(),[&srednia](int x){srednia+=x;});
    srednia /= vec.size();
    cout<<"Srednia: "<<srednia<<endl;

    int even=0;
    for_each(vec.begin(), vec.end(),[&even](int x){if(x%2==0){even++;}});
    cout<<"Patrzyste:"<<even<<endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }), vec.end());
    sort(vec.begin(),vec.end(),[](int x, int y){if(x%2<y%2){return x<y;}return y>x;});
    transform(vec.begin(),vec.end(),vec.begin(),[](int x){return x*(-1);});
    for_each(vec.begin(), vec.end(),[](int x){cout<<x<<"|";});
    int wart = -9;
    cout<<endl;
    cout<<count_if(vec.begin(),vec.end(),[wart](int x){return x<wart;})<<endl;

    vector<Car> samochody;
    samochody.push_back(Car("opel",2015,5.4));
    samochody.push_back(Car("bmw",2010,2.4));
    samochody.push_back(Car("audi",2020,6.6));
    sort(samochody.begin(),samochody.end(),[](const Car &x, const Car &y){return x.get_rok_prod()<y.get_rok_prod();});
    int licznik=0;
    for(Car x:samochody) {
        licznik++;
        cout<<"Samochod: "<<licznik<<" ";
        x.show();
    }
    sort(samochody.begin(),samochody.end(),[](const Car &x, const Car &y){return x.get_poj_silnika()>y.get_poj_silnika();});
    licznik=0;
    for(Car x:samochody) {
        licznik++;
        cout<<"Samochod: "<<licznik<<" ";
        x.show();
    }

    vector<string> xx;
    xx.push_back("adasdd");
    xx.push_back("asdasdasds");
    xx.push_back("asd");
    tuple<int,float,string> wynik = zad12_3(xx);
    cout<<"Najkrotsze "<<get<0>(wynik)<<endl;
    cout<<"Srednie "<<get<1>(wynik)<<endl;
    cout<<"Najdluzsze "<<get<2>(wynik)<<endl;
    return 0;
}