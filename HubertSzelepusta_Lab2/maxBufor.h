//
// Created by Daniel on 2024-10-13.
//

#ifndef MAXBUFOR_H
#define MAXBUFOR_H
#include "Bufor.h"


class maxBufor: public Bufor {
public:
    maxBufor();
    maxBufor(int size);
    ~maxBufor();
    double calculate() override;
    void add(int value) override;
};



#endif //MAXBUFOR_H
