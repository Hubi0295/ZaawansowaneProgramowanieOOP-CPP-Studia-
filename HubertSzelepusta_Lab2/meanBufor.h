

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
