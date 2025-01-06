//
// Created by Daniel on 2024-11-17.
//

#ifndef OPERATION_H
#define OPERATION_H


class Operation {
public:
    int operator()(int a, int b) {
        return a - b;
    }

    int operator()(char a) {
        return (int) a - 32;
    }
};





#endif //OPERATION_H
