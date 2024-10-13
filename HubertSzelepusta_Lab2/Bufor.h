
#ifndef BUFOR_H
#define BUFOR_H



class Bufor {
private:
    int *pointer;
    int size;
    int index;
public:
    Bufor();
    Bufor(int size1);
    virtual ~Bufor();
    virtual void add(int value);
    virtual double calculate()=0;
    int getSize();
    int getIndex();
    int getTab(int i);
    int getFirst();
    void setFirst(int value);
    void setTab(int pos, int value);
    void show();
    void incrementIndex();
};



#endif //BUFOR_H
