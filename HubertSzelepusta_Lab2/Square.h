

#ifndef SQUARE_H
#define SQUARE_H



#include "Figure.h"

class Square: public Figure
{
private:
    float a;
public:
    Square(float a1);
    ~Square();
    virtual void calculateArea() override;
    void show();
    virtual void calculateCircuit() override;
};


#endif //SQUARE_H
