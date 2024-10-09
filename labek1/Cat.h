#ifndef CAT_H
#define CAT_H
#include "Animal.h"


class Cat:public Animal{
private:
    int levelOfMouseHunting;
    int *mice;
public:
    Cat(int limbs1,string name,bool is_protected);
    Cat();
    void initCat(int levelOfMouseHunting1);
    void initMice();
    int getLevelOfMouseHunting();
    void setLevelOfMouseHunting(int value);
    int getMice(int index);
    void giveVoice();
    void info();
    static void howManyCats(Cat a[],int length);

};




#endif //CAT_H
