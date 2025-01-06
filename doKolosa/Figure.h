//
// Created by Hubert on 11.12.2024.
//

#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
using namespace std;
class Figure {
private:
    float area;
public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area);
    virtual void calculateArea()=0;
    virtual void show();
};



#endif //FIGURE_H
