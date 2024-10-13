//
// Created by Daniel on 2024-10-13.
//

#ifndef MEANBUFOR_H
#define MEANBUFOR_H
#include "Bufor.h"


class meanBufor: public Bufor {
public:
    meanBufor();
    meanBufor(int size);
    ~meanBufor();
    double calculate() override;

};



#endif //MEANBUFOR_H
