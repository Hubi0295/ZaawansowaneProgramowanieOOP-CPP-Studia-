//
// Created by Hubert on 28.10.2024.
//

#include "CompareBySumDigits.h"
bool CompareBySumDigits::operator( )(int x1, int x2) {
    int a1=0;
    while(x1!=0) {
        a1+=x1%10;
        x1/=10;
    }
    int a2=0;
    while(x2!=0) {
        a2+=x2%10;
        x2/=10;
    }
    return a1<a2;
}