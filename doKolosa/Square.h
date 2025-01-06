//
// Created by Hubert on 11.12.2024.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "Figure.h"


class Square: public Figure {
private:
    float a;
public:
    Square(float a1);
    ~Square();
    virtual void calculateArea() override;
    virtual void show() override;
};



#endif //SQUARE_H
