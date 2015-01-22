#include "Striker.h"
#include <Utility.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
Striker::Striker()
{
    create_line(2.0f,0.0f);
    this->angle_max[0]=-1.5f;
    this->angle_max[1]=1.5f;
}

Striker::~Striker()
{
    //dtor
}

void Striker::create_line(float length, float angle) {
    this->length=length;
    this->angle=angle;
}

void Striker::move_left() {
    if(fabs(this->__x-this->strip)<this->max_width)
        this->position(this->__x-this->strip,this->__y);
}

void Striker::move_right() {
    if(fabs(this->__x+this->strip)<this->max_width)
        this->position(this->__x+this->strip,this->__y);
}

void Striker::rotate_left() {
    if((this->angle-this->strip) > this->angle_max[0])
        this->angle=this->angle-this->strip;
}

void Striker::rotate_right() {
//    std::cout<<this->angle<<" degree\n";
    if((this->angle+this->strip) < this->angle_max[1])
        this->angle=this->angle+this->strip;
}

void Striker::increase_power() {
    if(this->length+this->strip <5.5f)
        this->length=this->length+this->strip;
}
void Striker::decrease_power() {
    if(this->length-this->strip > 0.5f)
        this->length=this->length-this->strip;
}
//void Striker::rotate_right() {
//    if(fabs(this->__x+this->strip)<this->max_width)
//        this->position(this->__x+this->strip,this->__y);
//}

void Striker::draw() {
    Utility *sketch=new Utility;
    if(this->getvx()==0.0f && this->getvy()==0.0f )
    {
        glLineWidth(2.0f);
        sketch->draw_line(1.0f,0.0f,0.0f,this->__x,this->__y,this->__x+(this->length)*sinf(this->angle),this->__y+(this->length)*cosf(this->angle));
        glLineWidth(1.0f);
    }
    sketch->filled_circle(this->__r,this->__g,this->__b,this->__x,this->__y,this->__radius);
}

void Striker::shoot() {
    float power=(this->length/15.0f);
    if(this->getvx()==0 && this->getvy()==0)
        this->v(power*sinf(this->angle),power*cosf(this->angle));
}

void Striker::limit(float max_width)
{
    this->max_width=max_width;
}

void Striker::set_angle(float angle)
{
    //-3.15f & 0.0f
    this->angle=angle;
}

void Striker::set_limit(float angle1,float angle2)
{
    //-3.15f & 0.0f
    this->angle_max[0]=angle1;
    this->angle_max[1]=angle2;
}
