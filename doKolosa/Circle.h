//
// Created by Hubert on 11.12.2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"


class Circle: public Figure {
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;

};



#endif //CIRCLE_H
