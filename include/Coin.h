#ifndef COIN_H
#define COIN_H

#include "object.h"

class Coin : public Object {
protected :
    float __radius;
    int pocket=0;
    int id=-10;
public :
//Getting values
    Coin();
    bool notPocketed();
    float gradius();
    void setId(int);
    int getId();
    virtual void draw();
    void debug();
//Setting values
    void radius(float r);
    void rgb(float r, float g, float b);
    void pocketted();
};

#endif // COIN_H
