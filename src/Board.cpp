#include "Board.h"
#include "Utility.h"
#include "Corner.h"
#include <cmath>
#include <CVector3.h>
#include <GL/glut.h>
#include <iostream>
#define PI 3.141592
#define XY_NORMALIZE 4.5f/75.0f

Board::Board(float w=4.0f,float h=4.0f)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            this->processing[i][j]=0;
    this->width=w;
    this->reset=0;
    this->height=h;
    this->tplayer=1;
    this->foul=0;
    this->rotate_value=0;
    this->score=30;
    this->game_is_on=0;
    this->s_w=(this->width/2)*0.75f;
    this->s_h=(this->height/2)*0.75f;
    this->place_corners();
    this->add_striker(1.0f,1.0f,0.0f,0.0f,-this->s_h*0.92f,0.25f);
    this->striker->setId(10);
    this->add_coins();
    this->left=this->right=0;
}

void Board::convert_to_multi(int i)
{
    this->multi=i;
}
void Board::player_count(int i)
{
    this->tplayer=i;
}

void Board::dark_theme()
{
    this->rgb(0.02f,0.06f,0.15f);
    this->drgb(0.32f,0.40f,0.55f);
    this->brgb(1.0f,1.0f,1.0f);
}

void Board::light_theme()
{
    this->rgb(0.98f,0.94f,0.85f);
    this->drgb(0.68f,0.60f,0.45f);
    this->brgb(0.0f,0.0f,0.0f);
}

void Board::add_striker(float r,float g,float b,float x,float y,float rad){
    Striker *created=new Striker;
    created->rgb(r,g,b);
    created->position(x,y);
//    created->v(0.15f,0.0f);
    created->radius(rad);
    created->limit(this->s_w*0.83f);
    created->mass(4.0f);
    this->striker=created;
    this->items[items_count++]=this->striker;
}

void Board::place_striker(float x,float y) {
    striker->position(x,y);
}

void Board::place_corners(){
    float w=(this->width/2),h=(this->height/2),r=this->corner_sq;
    for(int i=0;i<4;i++){
        this->corner[i].rgb(0.5f,0.5f,0.5f);
        this->corner[i].radius(r);
    }
    this->corner[0].position(-w+r,h-r);
    this->corner[1].position(-w+r,-h+r);
    this->corner[2].position(w-r,h-r);
    this->corner[3].position(w-r,-h+r);
}

void Board::rgb(float r, float g, float b) {
    this->__r = r;
    this->__g = g;
    this->__b = b;
}
void Board::drgb(float r, float g, float b) {
    this->__dr = r;
    this->__dg = g;
    this->__db = b;
}
void Board::brgb(float r, float g, float b) {
    this->__br = r;
    this->__bg = g;
    this->__bb = b;
}

void Board::draw_corners() {
    for(int i=0;i<4;i++)
        this->corner[i].draw();
}

void Board::add_coin(float r,float g,float b,float x,float y,float radius,int id){
    Object *new_item = new Coin;
    new_item->position(x,y);
    new_item->radius(radius);
    new_item->mass(2.0f);
    new_item->rgb(r,g,b);
    new_item->setId(id);
    new_item->v(0.0f,-0.0f);
    this->items[this->items_count++]=new_item;
}

void Board::add_coins(){
    Utility *sketch = new Utility;
    float angle=0;
    for(int i=0;i<8;i++)
    {
        this->add_coin(0.2f,0.2f,0.2f,sketch->rotatex(1.0f,0.0f,angle), sketch->rotatey(1.0f,0.0f,angle),0.15f,1);
        angle += 42.0f;
    }
    angle=21.0f;
    for(int i=0;i<8;i++)
    {
        this->add_coin(1.0f,1.0f,1.0f,sketch->rotatex(1.0f,0.0f,angle), sketch->rotatey(1.0f,0.0f,angle),0.15f,0);
        angle += 42.0f;
    }
    this->add_coin(1.0f,0.0f,0.0f,0.0f,0.0f,0.15f,50);
}

void Board::corner_beautify()
{
    Utility *sketch= new Utility;
    float w=(this->width/2),h=(this->height/2);

    sketch->filled_top_given(this->__dr,this->__dg,this->__db,-w,h,this->corner_sq);
    sketch->filled_top_given(this->__dr,this->__dg,this->__db,-w,-h+this->corner_sq,this->corner_sq);
    sketch->filled_top_given(this->__dr,this->__dg,this->__db,w-this->corner_sq,h,this->corner_sq);
    sketch->filled_top_given(this->__dr,this->__dg,this->__db,w-this->corner_sq,-h+this->corner_sq,this->corner_sq);
}

void Board::main_board(){
    Utility *sketch= new Utility;
    float w=(this->width/2), h=(this->height/2);
    sketch->filled_rectangle(this->__dr,this->__dg,this->__db,-w-0.2f,-h-0.2f,-w-0.2f,h+0.2f,w+0.2f,h+0.2f,w+0.2f,-h-0.2f);
    sketch->filled_rectangle(this->__r,this->__g,this->__b,-w,-h,-w,h,w,h,w,-h);
}

void Board::draw(){
    if(this->player && this->multi)
        glRotatef(180,0.0f,0.0f,1.0f);
    this->game_is_on=1;
    this->main_board();
    this->corner_beautify();
    this->draw_corners();
    this->striker_area();
    this->background_features();
    this->draw_coins();
    this->striker->draw();
    if(this->player && this->multi)
        glRotatef(180,0.0f,0.0f,1.0f);
    this->display_score();
    this->display_pocketed();
    if(this->multi==1)
    {
        this->chance_kiski();
    }
    else
    {

    }
}

void Board::chance_kiski(){
    Utility *sketch= new Utility;
    if(this->player==0)
        sketch->write_text(1.0f,0.0f,0.0f,-7.0f,4.65f,0,"Player 1 chance (Put WHITE balls)");
    if(this->player==1)
        sketch->write_text(1.0f,0.0f,0.0f,-7.0f,4.65f,0,"Player 2 chance (Put BLACK balls)");
}

void Board::display_pocketed() {
    Object *temp=new Coin;
    Utility *sketch = new Utility;
    float x=-6.5f,y=-3.5f;
    for(int i=0;i<pocketed_count;i++)
    {
        temp->setId(this->pocketed[i]->getId());
        if(temp->getId()==1)
            temp->rgb(0.0f,0.0f,0.0f);
        if(temp->getId()==0)
            temp->rgb(1.0f,1.0f,1.0f);
        if(temp->getId()==50)
            temp->rgb(1.0f,0.0f,0.0f);
        temp->position(x,y);
        temp->radius(0.15f);
        sketch->filled_top_given(0.9f,0.5f,0.5f,x-0.2f,y+0.2f,0.4f);
        temp->draw();
        y+=0.4f;
    }
}

void Board::draw_coins() {
    for(int i=1;i<this->items_count;i++)
        this->items[i]->draw();
}

void Board::display_score() {
    char temp[100];
    Utility *sketch = new Utility;
    sketch->filled_top_given(0.3f,0.7f,0.4f,-7.1f,4.5f,1.5f);
    if(this->multi==0)
    {
        sketch->write_text(0.0f,1.0f,1.0f,-7.0f,4.0f,1,"Score");
        itoa(this->score,temp,10);
        sketch->write_text(1.0f,1.0f,1.0f,-7.0f,3.5f,1,temp);
    }
    else
    {
        sketch->write_text(0.0f,1.0f,1.0f,-7.0f,4.0f,1,"Left balls");
        int countr=0;
        for(int i=0;i<items_count;i++)
        {
            if(this->items[i]->notPocketed() && this->items[i]->getId()==this->player)
                countr++;
        }
        itoa(countr,temp,10);
        sketch->write_text(1.0f,1.0f,1.0f,-7.0f,3.5f,1,temp);
    }
}

void Board::background_features(){
    Utility *sketch=new Utility;
    float x,y;
    //to draw main center
    sketch->filled_circle(this->__dr,this->__dg,this->__db,0.0f,0.0f,0.2f);

    glLineWidth(2.0f);
    sketch->empty_circle(this->__br,this->__bg,this->__bb,0.0f,0.0f,1.18f);
    glLineWidth(1.0f);
    sketch->draw_triangle(this->__dr,this->__dg,this->__db,1.18f,0.0f,-(1.17f/sqrt(2))+0.2f,-(1.17f*sqrt(3)/2.0f),-(1.17f/sqrt(2))+0.2f,(1.17f*sqrt(3)/2.0f));
    sketch->draw_triangle(this->__dr,this->__dg,this->__db,-1.18f,0.0f,(1.17f/sqrt(2))-0.2f,-(1.17f*sqrt(3)/2.0f),(1.17f/sqrt(2))-0.2f,(1.17f*sqrt(3)/2.0f));
    //to draw 4 lines between corner and main center
    float angle[4]={160,240,80,320};
    for(int i=0;i<4;i++)
    {
        x = this->corner[i].xpos();
        y = this->corner[i].ypos();
        glLineWidth(2.0f);
        sketch->draw_line(this->__br,this->__bg,this->__bb,(x-0)*0.85f,(y-0)*0.85f,(x-0)*0.4f,(y-0)*0.4f);
        glLineWidth(1.0f);
        sketch->incomplete_circle(this->__br,this->__bg,this->__bb,(x-0)*0.4f,(y-0)*0.4f,0.5f,angle[i]);
    }
}

void Board::striker_area(){
//    15% of width/height
    Utility *sketch= new Utility;
    float w=(this->width/2)*0.75f,h=(this->height/2)*0.75f;
    float aw=w*0.90f,ah=h*0.90f;
    float cord[4][4] = {
        -aw,h,aw,h,
        -aw,-h,aw,-h,
        w,-ah,w,ah,
        -w,-ah,-w,ah
    };
    float r=0.2f;
    for(int i=0;i<4;i++)
    {
        if(cord[i][0]==cord[i][2])
        {
            float fraction = r*2/cord[i][2];
            if(fraction<0)
                fraction*=-1;
            float m = 1.0000f - fraction;
            glLineWidth(2.0f);
            sketch->draw_line(this->__br,this->__bg,this->__bb,cord[i][0],cord[i][1]+r,cord[i][2],cord[i][3]-r);
            glLineWidth(1.0f);
            sketch->draw_line(this->__br,this->__bg,this->__bb,cord[i][0]*m,cord[i][1]+r,cord[i][2]*m,cord[i][3]-r);
        }
        else
        {
            float fraction = r*2/cord[i][1];
            if(fraction<0)
                fraction*=-1;
            float m = 1.0000f - fraction;
            glLineWidth(2.0f);
            sketch->draw_line(this->__br,this->__bg,this->__bb,cord[i][0]+r,cord[i][1],cord[i][2]-r,cord[i][3]);
            glLineWidth(1.0f);
            sketch->draw_line(this->__br,this->__bg,this->__bb,cord[i][0]+r,cord[i][1]*m,cord[i][2]-r,cord[i][3]*m);
        }
        float a=cord[i][0]+0.2f,b=cord[i][1]+0.2f,c=cord[i][2]+0.2f,d=cord[i][3]+0.2f;
        if(a>0)
            a-=0.4f;
        if(b>0)
            b-=0.4f;

        if(c>0)
            c-=0.4f;
        if(d>0)
            d-=0.4f;

        sketch->empty_circle(this->__br,this->__bg,this->__bb,a,b,0.2f);
        sketch->empty_circle(this->__br,this->__bg,this->__bb,c,d,0.2f);
        sketch->filled_circle(0.5f,0.0f,0.0f,a,b,0.175f);
        sketch->filled_circle(0.5f,0.0f,0.0f,c,d,0.175f);
    }
}

Board::~Board()
{
    //dtor
}
void Board::move_coins(){
    for(int i=0;i<items_count;i++)
    {
        if(this->items[i]->notPocketed())
            this->items[i]->update_location(1);
    }
}
void Board::check_wall()
{
    for(int i=0;i<items_count;i++)
    {
        if(fabsf(this->items[i]->xpos())+this->items[i]->gradius()>=this->width/2.000f)
        {
            this->items[i]->setvx(-1.0000f*this->items[i]->getvx());
            float sign=this->items[i]->getvx()/fabsf(this->items[i]->getvx());
            this->items[i]->position(-1*sign*(this->width/2 - this->items[i]->gradius()),this->items[i]->ypos());
        }
        if(fabsf(this->items[i]->ypos())+this->items[i]->gradius()>=this->height/2.000f)
        {
            this->items[i]->setvy(-1.0000f*this->items[i]->getvy());
            float sign=this->items[i]->getvy()/fabsf(this->items[i]->getvy());
            this->items[i]->position(this->items[i]->xpos(),-1*sign*(this->height/2 - this->items[i]->gradius()));
        }
    }
}

bool Board::isRunning() {
    for(int i=0;i<items_count;i++)
        if(!this->items[i]->stopped())
            return true;
    return false;
}

bool Board::isStopped() {
    return !isRunning();
}

void Board::set_not_required(int i) {
    this->not_color_required=i;
}

void Board::pocket_coin() {
    for(int i=0;i<4;i++)
        for(int j=0;j<items_count;j++)
        if(this->corner[i].isCollided(this->items[j]) && this->items[j]->notPocketed())
        {
            if(j!=0)
            {
                this->items[j]->pocketted();
                this->pocketed[pocketed_count++]=this->items[j];
            }
                if(this->items[j]->getId() == this->not_color_required)
                    this->score-=5;
                else if(this->items[j]->getId() == this->queen)
                    this->score+=50;
                else if(this->items[j]->getId() == 10 && this->foul)
                    this->score-=5;
                else if(this->items[j]->getId()!=10)
                    this->score+=10;
                this->player=1-this->player;
//                std::cout<<score<<" "<<this->items[j]->getId()<<" pocketed\n";
            this->items[j]->v(0.0f,0.0f);
        }
}

void Board::update(){
    this->check_wall();
    this->collision_handle();
    this->pocket_coin();
    this->move_coins();
    this->reset_striker();
}

void Board::reset_striker()
{
    if(this->reset && this->isStopped())
    {
        Sleep(500);
        this->reset=0;
        this->player=1-this->player;
        if(this->player==0 || this->multi==0)
        {
            this->striker->set_angle(0.0f);
            this->striker->set_limit(-1.5f,1.5f);
            this->place_striker(0.0f,-this->s_h*0.92f);
        }
        else
        {
            this->striker->set_angle(-3.15f);
            this->striker->set_limit(-4.7f,-1.65f);
            this->place_striker(0.0f,this->s_h*0.92f);
        }
    }
}

void Board::collision_handle() {
    int i,j;
    int collided[100][100];
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            collided[i][j]=0;
    for(i=0;i<items_count;i++)
        for(j=0;j<items_count;j++)
        {
            if(this->items[i]->notPocketed() && this->items[j]->notPocketed())
            {
                bool now_collided = this->items[i]->isCollided(this->items[j]);
                if(now_collided==1 && !collided[i][j] && i!=j && !this->processing[i][j])
                {
                    collided[i][j]=1;
                    collided[j][i]=1;
                    this->processing[i][j]=1;
                    this->processing[j][i]=1;
                    this->items[i]->collided(this->items[j]);
                    i=-1;
                    break;
                }
                else if(!now_collided && i!=j && this->processing[i][j])
                {
                    this->processing[i][j]=0;
                    this->processing[j][i]=0;
                }
            }
        }
}

void Board::handleKeys(unsigned char key, int x, int y) {
    if((key=='a' || key=='A')&& this->isStopped())
    {
        this->striker->rotate_left();
    }
    if((key=='c' || key=='C') && this->isStopped())
    {
        this->striker->rotate_right();
    }
    if(key==' ' && this->isStopped())
    {
        this->striker->shoot();
        this->reset=1;
    }
}

void Board::specialKeys(int key,int x,int y) {
    if(key==100 && this->isStopped() && (this->player==0 || this->multi==0))
    {
        this->striker->move_left();
    }
    else if(key==102 && this->isStopped() && (this->player==0 || this->multi==0))
    {
        this->striker->move_right();
    }
    else if(key==100 && this->isStopped() && (this->player==1 && this->multi==1))
    {
        this->striker->move_right();
    }
    else if(key==102 && this->isStopped() && (this->player==1 && this->multi==1))
    {
        this->striker->move_left();
    }

    if(key==101 && this->isStopped())
    {
        this->striker->increase_power();
    }
    if(key==103 && this->isStopped())
    {
        this->striker->decrease_power();
    }
}

void Board::mouseClick(int button, int state, int x, int y) {
    Utility *sketch=new Utility;
    CVector3 temp;
    float rotater;
    if(this->multi==1)
        rotater=cos(this->player*PI*180.0/180.0);
    else
        rotater=1;
    temp=sketch->getCord(x,y);
    float a=temp.fGetX()*XY_NORMALIZE*rotater,b=temp.fGetY()*XY_NORMALIZE*rotater;
    if(!game_is_on)
        return;
    if(button==0)
        this->left=!state;
    if(button==2)
        this->right=!state;

    if(button==0 && state)
    {
        this->striker->update_hover(a,b);
        this->striker->shoot();
        this->reset=1;
    }
}

void Board::mouseMotion(int x, int y) {
    Utility *sketch=new Utility;
    CVector3 temp;
    temp=sketch->getCord(x,y);
    float rotater;
    if(this->multi==1)
        rotater=cos(this->player*PI*180.0/180.0);
    else
        rotater=1;
    float a=temp.fGetX()*XY_NORMALIZE*rotater,b=temp.fGetY()*XY_NORMALIZE*rotater;
    if(!game_is_on)
        return;
    if(this->left)
    {
        this->striker->update_hover(a,b);
    }
    if(this->right)
    {
        this->striker->mouseSetLocation(a);
    }
}
