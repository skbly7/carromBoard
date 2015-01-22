#include "Corner.h"
#include "Utility.h"
Corner::Corner()
{
    //ctor
}

Corner::~Corner()
{
    //dtor
}

void Corner::shadow() {
    Utility *sketch=new Utility;
    sketch->filled_circle(0.0f,0.0f,0.0f,this->__x,this->__y,this->__radius+0.02f);
}

void Corner::draw() {
    Utility *sketch=new Utility;
    sketch->filled_circle(this->__r,this->__g,this->__b,this->__x,this->__y,this->__radius);
}
