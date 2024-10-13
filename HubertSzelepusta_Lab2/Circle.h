//
// Created by Daniel on 2024-10-12.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"

class Circle: public Figure
{
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;
    virtual void calculateCircuit() override;
};


#endif //CIRCLE_H
