#include "Utility.h"
#include <GL/glut.h>
#include <cmath>
Utility::Utility()
{
    //ctor
}

Utility::~Utility()
{
    //dtor
}

float Utility::rotatex(float x,float y,float deg){
    return (x*cos(this->to_radian(deg)))-(y*sin(this->to_radian(deg)));
}

float Utility::rotatey(float x,float y,float deg){
    return (x*sin(this->to_radian(deg)))-(y*cos(this->to_radian(deg)));
}

void Utility::filled_rectangle(float r,float g,float b,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    glPushMatrix();
    glColor3f(r,g,b);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPopMatrix();
}
void Utility::filled_top_given(float r,float g,float b,float x,float y,float width)
{
    glPushMatrix();
    glColor3f(r,g,b);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y-width);
    glVertex2f(x,y-width);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPopMatrix();
}
float Utility::to_radian(float deg)
{
    return (deg*(3.41231321321))/180;
}
void Utility::filled_circle(float red,float green,float blue,float a,float b,float r)
{
    glPushMatrix();
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0 ; i<360 ; i++) {
       glVertex2f(r * cos(this->to_radian(i))+a, r * sin(this->to_radian(i))+b);
    }
    glEnd();
    glPopMatrix();
}
void Utility::empty_circle(float red,float green,float blue,float a,float b,float r)
{
    glPushMatrix();
    glColor3f(red, green, blue);
    glBegin(GL_LINE_LOOP);
    for(int i=0 ; i<330 ; i++) {
       glVertex2f(r * cos(this->to_radian(i))+a, r * sin(this->to_radian(i))+b);
    }
    glEnd();
    glPopMatrix();
}
void Utility::incomplete_circle(float red,float green,float blue,float a,float b,float r,float angle)
{
    glPushMatrix();
    glColor3f(red, green, blue);
    glBegin(GL_LINE_STRIP);
    for(int i=angle ; i<260+angle ; i++) {
       glVertex2f(r * cos(this->to_radian(i))+a, r * sin(this->to_radian(i))+b);
    }
    glEnd();
    glTranslatef(a, b,0);
    glTranslatef(-a,-b,0);
    glPopMatrix();
}
void Utility::draw_line(float r,float g,float b,float x1,float y1,float x2,float y2)
{
    glPushMatrix();
    glColor3f(r,g,b);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glPopMatrix();
}
void Utility::draw_triangle(float r,float g,float b,float x1,float y1,float x2,float y2,float x3,float y3) {
    this->draw_line(r,g,b,x1,y1,x2,y2);
    this->draw_line(r,g,b,x1,y1,x3,y3);
    this->draw_line(r,g,b,x3,y3,x2,y2);
}
void Utility::draw_rotate_triangle(float r,float g,float b,float dr,float dg,float db,float x1,float y1,float x2,float y2,float x3,float y3,float angle) {
    //todo
    return;
}
void Utility::write_text(float r, float g, float b, float x, float y, int font, char *str)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(str);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  }
}
