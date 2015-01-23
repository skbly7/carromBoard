#include "Coin.h"
#include "object.h"
#include "Utility.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void Coin::pocketted()
{
    this->pocket=1;
}

bool Coin::notPocketed()
{
    return !this->pocket;
}

float Coin::gradius() {
    return this->__radius;
}

int Coin::getId() {
    return this->id;
}

void Coin::setId(int i) {
    this->id=i;
}

void Coin::radius(float r) {
    this->__radius = r;
}

void Coin::debug(){
    std::cout<<this->__radius<<std::endl;
}

void Coin::rgb(float r, float g, float b) {
    this->__r = r;
    this->__g = g;
    this->__b = b;
}

void Coin::draw() {
    if(pocket)
        return;
    Utility *sketch=new Utility;
    sketch->filled_circle(1.0f-this->__r,1.0f-this->__g,1.0f-this->__b,this->__x,this->__y,this->__radius);
    sketch->filled_circle(this->__r,this->__g,this->__b,this->__x,this->__y,this->__radius);
    sketch->empty_circle(1.0f-this->__r,1.0f-this->__g,1.0f-this->__b,this->__x,this->__y,this->__radius/2);
}

Coin::Coin() {
    this->pocket=0;
    this->__mu=0.01f;
}
