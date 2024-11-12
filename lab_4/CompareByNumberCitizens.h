//
// Created by Hubert on 28.10.2024.
//

#ifndef COMPAREBYNUMBERCITIZENS_H
#define COMPAREBYNUMBERCITIZENS_H
#include "City.h"


class CompareByNumberCitizens {
public:
    bool operator( )(City &c1, City &c2);
};



#endif //COMPAREBYNUMBERCITIZENS_H
