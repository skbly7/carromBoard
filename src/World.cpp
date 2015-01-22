#include "World.h"
#include "Coin.h"
#include "Board.h"
#include <GL/glut.h>
#include <Utility.h>
#include <iostream>
#define UPDATE_SPEED 10
World *World::instance = NULL;

World::World(int width = 640, int height = 480) {
    this->width = width;
    this->height = height;
    this->taking_options=0;
}


void World::add_board() {
    this->board = new Board(9,9);
    this->board->rgb(111,111,111);
    this->board->light_theme();
    this->board->convert_to_multi(1);
}


void World::debug_objects() {
    return;
}

void World::handleResize(int w, int h) {
    instance->hResize(w, h);
}

void World::drawEverything() {
    instance->draw();
}

World::~World(){
}
void World::hResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) w / (float) h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void World::start(int argc, char *argv[]) {
    instance = this;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(this->width, this->height);
    glutInitWindowPosition(WINDOW_X_POSITION, WINDOW_Y_POSITION);

    glutCreateWindow("SHIVAM");
    this->initRendering();
    glutDisplayFunc(drawEverything);
    glutIdleFunc(drawEverything);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(specialKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(UPDATE_SPEED, update, 0);
    glutMainLoop();
}


void World::initRendering() {
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void World::draw() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(1,1,1,1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -12.0f);
//FOR ROTATION
//glRotatef(180, 0.0f, 0.0f, 1.0f);
this->drawAll();
glutSwapBuffers();
}

void World::drawAll()
{
    if(this->taking_options==-1)
        this->board->draw();
    else
        this->taking_inputs();
}

void World::taking_inputs(){
    Utility *sketch= new Utility;
    if(this->taking_options==0)
    {
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Welcome Player(s) !!");
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,1.5f,10,"Carrom game prepared for Graphics Course.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.5f,10,"Lets check your keyboard... :P");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.0f,10,"Press 1 to start.");
        sketch->write_text(1.0f,0.0f,0.0f,1.5f,-3.0f,10,"- Shivam Khandelwal (201403005)");
    }
    if(this->taking_options==1)
    {
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Type of game ?");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.5f,10,"1. Multiple Players (Two).");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.0f,10,"2. Single Player.");
        sketch->write_text(0.0f,0.5f,1.0f,-3.5f,-0.5f,10,"Enter your choice.......");
    }
    if(this->taking_options==2)
    {
        this->board->convert_to_multi(0);
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Choose level.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.5f,10,"1. All color coins + Red.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.0f,10,"2. One color coins only + Red.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.5f,10,"3. All color coins + Red + Foul.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.0f,10,"4. One color coins only + Red + Foul.");
        sketch->write_text(0.0f,0.5f,1.0f,-3.5f,-0.5f,10,"Enter your choice.......");
    }
    if(this->taking_options==3)
    {
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Color you wish to pocket.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.5f,10,"1. White.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.0f,10,"2. Black.");
        sketch->write_text(0.0f,0.5f,1.0f,-3.5f,0.5f,10,"Enter your choice.......");
    }
    if(this->taking_options==4)
    {
        this->board->convert_to_multi(1);
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Quick multiplayer rules :");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.5f,10,"* Player 1 would start (first choice)");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.0f,10,"* Player 1 has to pocket all the Black balls.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.5f,10,"* Player 2 has to pocket all the White balls.");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,0.0f,10,"* Queen is not assigned any points (You can use for extra chance).");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,-0.5f,10,"* Pocket any coin, to get extra chance.");
        sketch->write_text(0.0f,0.5,1.0f,-3.5f,-1.5f,10,"ALL THE BEST....... ( Press 1 )");
    }
    if(this->taking_options==5)
    {
        sketch->write_text(1.0f,0.0f,0.0f,-3.5f,2.0f,10,"Theme preference (Yes theme too...)");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.5f,10,"1. Light (Brownish).");
        sketch->write_text(1.0f,0.0f,1.0f,-3.5f,1.0f,10,"2. Dark (Purple/Violet type).");
        sketch->write_text(0.0f,0.5,1.0f,-3.5f,0.5f,10,"Enter your choice.......");
    }
    if(this->taking_options==6)
        this->taking_options=-1;
    return;
}

void World::options_set(unsigned char key, int x, int y){
    if(this->taking_options==0)
    {
        if(key=='1')
            this->taking_options=1;
    }
    else if(this->taking_options==1)
    {
        if(key=='1')
            this->taking_options=4;
        if(key=='2')
            this->taking_options=2;
    }
    else if(this->taking_options==2)
    {
        if(key == '3' || key=='4')
            this->board->foul=1;
        if(key=='1' || key=='3')
        {
            this->board->set_not_required(-10);
            this->taking_options=3;
        }
        if(key=='2' || key=='4')
            this->taking_options=2;
    }
    else if(this->taking_options==3)
    {
        if(key=='1' || key=='2')
            this->taking_options=5;
        if(key == '1')
            this->board->set_not_required(1);
        if(key == '2')
            this->board->set_not_required(0);
    }
    else if(this->taking_options==4)
    {
        if(key=='1')
            this->taking_options=5;
    }
    else if(this->taking_options==5)
    {
        if(key=='1')
        {
            this->board->light_theme();
        }
        else if(key=='2')
        {
            this->board->dark_theme();
        }
        if(key=='1'||key=='2')
            this->taking_options=6;
    }
}

void World::update(int value) {
    if(instance->taking_options==-1)
        instance->board->update();
    glutTimerFunc(UPDATE_SPEED, update, 0);
    return;
}

void World::handleKeypress(unsigned char key, int x, int y) {
    if(instance->taking_options==-1)
        instance->board->handleKeys(key,x,y);
    else
        instance->options_set(key,x,y);
    return;
}

void World::specialKeypress(int key, int x, int y) {
    instance->board->specialKeys(key,x,y);
    return;
}
