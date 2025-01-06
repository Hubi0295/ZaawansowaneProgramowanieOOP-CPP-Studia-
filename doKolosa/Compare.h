//
// Created by Hubert on 12.12.2024.
//

#ifndef COMPARE_H
#define COMPARE_H
#include "Student.h"


class Compare {
public:
    template<typename T>
    bool operator()(Student<T> &s1, Student<T>&s2);
};
template<typename T>
bool Compare::operator()(Student<T> &s1, Student<T> &s2) {
    return s1.getMark()<s2.getMark();

}



#endif //COMPARE_H
