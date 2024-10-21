//
// Created by Hubert on 21.10.2024.
//

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include "stdio.h"
using namespace std;

template <typename T>
class Array {
private:
    T *dane;
    int maxSize;
    int index;
public:
    Array() {
        maxSize = 10;
        index = 0;
        dane = new T[10];
    }
    Array(int maxSize) {
        this->maxSize = maxSize;
        dane = new T[maxSize];
        index = 0;
    }
    ~Array(){};
    void sortIt() {
        for (int i = 0; i < maxSize; i++) {
            for (int j = 0; j < maxSize - i - 1; j++) {
                if(dane[j] > dane[j + 1]) {
                    T temp = dane[j];
                    dane[j] = dane[j + 1];
                    dane[j + 1] = temp;
                }
            }
        }
    }
    T getMax() {
        T max = dane[0];
        for(int i=0;i<maxSize;i++) {
            if(dane[i] > max) {
                max = dane[i];
            }
        }
        return max;
    }
    void show() {
        for(int i=0;i<maxSize;i++) {
            cout<<i<<" "<<dane[i]<<endl;
        }
    }
    void add(T x) {
        if(index < maxSize) {
            dane[index]=x;
        }
        index++;
    }
    T getByIndex(int index) {
        return dane[index];
    }
};
template<>
class Array<string> {
private:
    string *dane;
    int maxSize;
    int index;
public:
    Array() {
        maxSize = 10;
        index = 0;
        dane = new string[10];
    }
    Array(int maxSize) {
        this->maxSize = maxSize;
        dane = new string[maxSize];
        index = 0;
    }
    ~Array(){};
    void sortIt() {
        for (int i = 0; i < maxSize; i++) {
            for (int j = 0; j < maxSize - i - 1; j++) {
                if(dane[j].length() > dane[j+1].length()) {
                    string temp = dane[j];
                    dane[j] = dane[j + 1];
                    dane[j + 1] = temp;
                }
            }
        }
    }
    string getMax() {
        string max = dane[0];
        for(int i=0;i<maxSize;i++) {
            if(dane[i].length() > max.length()) {
                max = dane[i];
            }
        }
        return max;
    }
    void show() {
        for(int i=0;i<maxSize;i++) {
            cout<<i<<" "<<dane[i]<<endl;
        }
    }
    void add(string x) {
        if(index < maxSize) {
            dane[index]=x;
        }
        index++;
    }
    string getByIndex(int index) {
        return dane[index];
    }
};


#endif //ARRAY_H
