//
// Created by Hubert on 13.12.2024.
//

#ifndef FUNKTORSTUDENTA_H
#define FUNKTORSTUDENTA_H
#include "subject.h"

class FunktorStudenta {
public:
        bool operator()(std::pair<const subject, int>&x){
            return x.second == 1;
        }
};
#endif //FUNKTORSTUDENTA_H
