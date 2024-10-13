//
// Created by Daniel on 2024-10-12.
//

#ifndef FIGURE_H
#define FIGURE_H


class Figure
{
private:
    float area;
public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area1);
    virtual void calculateArea()=0;
    void show();
    virtual void calculateCircuit()=0;
};




#endif //FIGURE_H
