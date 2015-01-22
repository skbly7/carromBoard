#include "object.h"
#include <iostream>
#include <cmath>
float Object::getvx() {
    return this->__vx;
}
float Object::getvy() {
    return this->__vy;
}
void Object::draw(){
}
void Object::debug(){
}
void Object::radius(float i){
}
float Object::radius(){
}
void Object::position(){
}
float Object::mass() {
    return this->__mass;
}
void Object::rgb(float r, float g, float b) {
    this->__r = r;
    this->__g = g;
    this->__b = b;
}
void Object::debug_coin() {
    std::cout<<this->__x<<" "<<this->__y<<std::endl;
}
void Object::setvx(float x) {
    this->__vx=x;
}
void Object::setvy(float y) {
    this->__vy=y;
}
void Object::mass(float m) {
    this->__mass=m;
}
void Object::v(float x, float y) {
    this->setvx(x);
    this->setvy(y);
}
void Object::position(float x, float y) {
    this->__x=x;
    this->__y=y;
}
float Object::xpos(){
    return this->__x;
}
float Object::ypos(){
    return this->__y;
}
void Object::apply_friction(int t=1) {
    //AT x-axis
    float vx= fabs(this->getvx());
    float vy= fabs(this->getvy());
    float den = sqrtf(vx*vx + vy*vy);
    float at_x = fabs((this->__mu)*(vx/den));
    float at_y = fabs((this->__mu)*(vy/den));
    if(vx-at_x > 0)
    {
        if(this->getvx()>0)
            this->setvx(this->getvx()-at_x);
        else
            this->setvx(this->getvx()+at_x);
    }
    else
        this->setvx(0.0f);

    //AT x-axis
    if(vy-at_y > 0)
    {
        if(this->getvy()>0)
            this->setvy(this->getvy()-at_y);
        else
            this->setvy(this->getvy()+at_y);
    }
    else
        this->setvy(0.0f);
}
void Object::update_location(int t=1) {
    this->apply_friction(t);
    this->position(this->xpos()+this->getvx(),this->ypos()+this->getvy());
}
float Object::gradius() {
    return 0.0f;
}
bool Object::stopped() {
    return ((this->getvx()==0)&&(this->getvy()==0));
}
bool Object::isCollided(Object *b)
{
    float min_distance= this->gradius()+b->gradius();
    float x_dist = this->xpos() - b->xpos();
    float y_dist = this->ypos() - b->ypos();
    float distance = sqrtf(x_dist*x_dist + y_dist*y_dist);
    if(distance <= min_distance)
     {
        return true;
     }
    return false;
}
void Object::pocketted(){
    return;
}
void Object::collided(Object *b)
{
    float E=0.7f;
    float m1 = this->mass();
    float m2 = b->mass();
    float d = sqrtf( (this->xpos() - b->xpos()) * (this->xpos() - b->xpos()) + (this->ypos() - b->ypos()) * (this->ypos() - b->ypos()));
    float un_x = (b->xpos() - this->xpos()) / d, un_y = (b->ypos() - this->ypos()) / d;
    float ut_x = -un_y, ut_y = un_x;
    float ua_n = (un_x * this->getvx()) + un_y * this->getvy(), ua_t = ut_x * this->getvx() + ut_y * this->getvy();
    float ub_n = un_x * b->getvx() + un_y * b->getvy(), ub_t = ut_x * b->getvx() + ut_y * b->getvy();
    float va_n = (E * m2 * (ub_n - ua_n) + m1 * ua_n + m2 * ub_n) / (m1 + m2);
    float vb_n = (E * m1 * (ua_n - ub_n) + m1 * ua_n + m2 * ub_n) / (m1 + m2);
    float va_t = ua_t, vb_t = ub_t; float vax_n = va_n * un_x, vay_n = va_n * un_y, vax_t = va_t * ut_x, vay_t = va_t * ut_y;
    float vbx_n = vb_n * un_x, vby_n = vb_n * un_y, vbx_t = vb_t * ut_x, vby_t = vb_t * ut_y;
    this->setvx(vax_n + vax_t);
    this->setvy(vay_n + vay_t);
    b->setvx(vbx_n + vbx_t);
    b->setvy(vby_n + vby_t);
}

bool Object::notPocketed()
{
    return true;
}

int Object::getId()
{
    return true;
}

void Object::setId(int)
{
    return;
}
