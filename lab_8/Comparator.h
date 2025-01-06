//
// Created by Hubert on 20.12.2024.
//

#ifndef COMPARATOR_H
#define COMPARATOR_H
#include "Student.h"


class Comparator {
public:
    bool operator()(const Student &s1, const Student &s2) const {
        return s1.ocena1() < s2.ocena1();
    }
};



#endif //COMPARATOR_H
