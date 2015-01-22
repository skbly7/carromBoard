//#include <iostream>
//#include <cmath>
//#include <GL/glut.h>
//#include "Coin.h"
//using namespace std;
//
//#define PI 3.141592653589
//#define DEG2RAD(deg) (deg * PI / 180)
//#define RAD2DEG(rad) (rad * 180 / PI)
//#define ROTATEX(x,y,deg) ((x * cos(DEG2RAD(deg)))-(y*sin(DEG2RAD(deg))))
//#define ROTATEY(x,y,deg) ((x * sin(DEG2RAD(deg)))+(y*cos(DEG2RAD(deg))))
//int ki=0;
//Coin black[4],white[4];
//Coin red(0,0.0f,0.0f,3.5f,1.0f,0.0f,0.0f,5.0f,0.0f,0.0f,50);
//Coin Striker(0,0.0f,-55.5f,4.5f,0.0f,1.0f,0.0f,6.0f,0.0f,0.0f,-5);
//
//// Function Declarations
//void drawScene();
//void update(int value);
//void drawBox(float len);
//void drawBox_hollow(float len);
//void drawBall_hollow(float rad,float x,float y);
//void drawHoles(float rad,float x,float y);
//void initRendering();
//void handleResize(int w, int h);
//void handleKeypress1(unsigned char key, int x, int y);
//void handleKeypress2(int key, int x, int y);
//void handleMouseclick(int button, int state, int x, int y);
//void handleMotionClick(int x, int y);
//void reset_new_chance();
//
//void Coin::createCoin()
//{
//    pair<float,pair<float,float> > color;
//    color = this->getcolour();
//    glColor3f(color.first,color.second.first,color.second.second);
//    glBegin(GL_TRIANGLE_FAN);
//    for(int i=0 ; i<360 ; i++) {
//        glVertex2f(this->get_x()+(this->get_radius() * cos(DEG2RAD(i))), this->get_y()+(this->get_radius() * sin(DEG2RAD(i))));
//    }
//    glEnd();
//}
//
//float ball_rad = 5.0f;
//float box_len = 160.0f;
//float inner_box_len = 150.0f;
//float innermost = 101.6f;
//float hover_x = 0.0f;
//float hover_y = -15.0f;
//float hover_rot = 1.0f;
//int display_hover = 1;
//float power = 10.0f;
//int windowWidth,windowHeight,play = 0;
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//
//    int w = glutGet(GLUT_SCREEN_WIDTH);
//    int h = glutGet(GLUT_SCREEN_HEIGHT);
//    windowWidth = w * 2 / 3;
//    windowHeight = h * 2 / 3;
//
//    glutInitWindowSize(windowWidth, windowHeight);
//    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);
//
//    glutCreateWindow("Carrom");  // Setup the window
//    initRendering();
//
//    // Register callbacks
//    glutDisplayFunc(drawScene);
//    glutIdleFunc(drawScene);
//    glutKeyboardFunc(handleKeypress1);
//    glutSpecialFunc(handleKeypress2);
//    glutMouseFunc(handleMouseclick);
//    glutMotionFunc(handleMotionClick);
//    glutReshapeFunc(handleResize);
//    glutTimerFunc(10, update, 0);
//
//    glutMainLoop();
//    return 0;
//}
//
//void reset_new_chance()
//{
//    Striker.set_x(0.0f);
//    Striker.set_y(-55.0f);
//    display_hover = 1;
//    power = 10.0f;
//    hover_x = 0.0f;
//    hover_y = -15.0f;
//    play = 0;
//}
//
//void initialize_board()
//{
//    float rtang = 0.0f;
//    for(int i = 0; i < 4 ; i++)
//    {
//        black[i] = Coin(0,ROTATEX(10.0f,0.0f,rtang),ROTATEY(10.0f,0.0f,rtang),3.5f,0.0f,0.0f,0.0f,5.0f,1.0f,1.0f,5);
//        black[i].createCoin();
//        rtang += 90.0f;
//    }
//
//    //Coin white[4];
//    rtang = 45.0f;
//    for(int i = 0; i < 4 ; i++)
//    {
//        white[i] = Coin(0,ROTATEX(10.0f,0.0f,rtang),ROTATEY(10.0f,0.0f,rtang),3.5f,1.0f,1.0f,1.0f,5.0f,0.0f,0.0f,5);
//        white[i].createCoin();
//        rtang += 90.0f;
//    }
//    red.createCoin();
//    Striker.createCoin();
//}
//// Function to draw objects on the screen
//void drawScene() {
//
//    if(ki==0)
//    {
//        initialize_board();
//        ki++;
//    }
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glPushMatrix();
//
//    // Draw Box
//    glTranslatef(0.0f, 0.0f, -200.0f);
//    glColor3f(0.60f, 0.40f, 0.12f);
//    drawBox(box_len);
//
//    glColor3f(1.0f,0.854f,0.725f);
//    drawBox(inner_box_len);
//
//    glPushMatrix();
//    glColor3f(0.0f, 0.0f, 0.0f);
//    drawHoles(ball_rad,69.5,69.5);
//    drawHoles(ball_rad,-69.5,69.5);
//    drawHoles(ball_rad,-69.5,-69.5);
//    drawHoles(ball_rad,69.5,-69.5);
//    glPopMatrix();
//
//    glColor3f(0.60f, 0.40f, 0.12f);
//    drawBox_hollow(120.4f);
//    drawBox_hollow(innermost);
//
//    glPushMatrix();
//    glColor3f(1.0f, 0.0f, 0.0f);
//    drawBall_hollow(5.0f,0.0,0.0);
//    drawBall_hollow(15.0f,0.0,0.0);
//    glPopMatrix();
//
//    for(int i = 0; i < 4 ; i++)
//    {
//        white[i].createCoin();
//        black[i].createCoin();
//    }
//    red.createCoin();
//    Striker.createCoin();
//
//    if(display_hover)
//    {
//        glColor3f(0.0f,0.0f,1.0f);
//        glBegin(GL_LINE_STRIP);
//        glVertex2f(Striker.get_x(), (Striker.get_y()+Striker.get_radius()));
//        glVertex2f(hover_x,hover_y);
//        glEnd();
//    }
//
//    glColor3f(0.0f,0.0f,0.0f);
//    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//    glBegin(GL_QUADS);
//    glVertex2f(100.0f,-40.0f);
//    glVertex2f(100.0f,40.0f);
//    glVertex2f(120.0f,40.0f);
//    glVertex2f(120.0f,-40.0f);
//    glEnd();
//    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//
//    glColor3f(1.0f,1.0f,0.0f);
//    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
//    glBegin(GL_QUADS);
//    glVertex2f(100.2f,-39.8f);
//    glVertex2f(100.2f,power);
//    glVertex2f(119.8f,power);
//    glVertex2f(119.8f,-39.8f);
//    glEnd();
//    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
//
//    glPopMatrix();
//    glutSwapBuffers();
//}
//
//void update(int value) {
//
//    if(play)
//    {
//        bool sign;
//        float x=Striker.get_vx(),y=Striker.get_vy();
//        float friction=0.001f;
//        float x_comp=abs((x/(y+x))*friction);
//        float y_comp=abs((y/(y+x))*friction);
//        if(x>0)
//        {
//            sign=true;
//            Striker.set_vx(Striker.get_vx()-x_comp);
//        }
//        else if(x<0)
//        {
//            sign=false;
//            Striker.set_vx(Striker.get_vx()+x_comp);
//        }
//        if((Striker.get_vx()>0) != sign)
//            Striker.set_vx(0.0f);
//
//        if(y>0)
//        {
//            sign=true;
//            Striker.set_vy(Striker.get_vy()-y_comp);
//        }
//        else if(y<0)
//        {
//            sign=false;
//            Striker.set_vy(Striker.get_vy()+y_comp);
//        }
//        if((Striker.get_vy()>0) != sign)
//            Striker.set_vy(0.0f);
//
//        if(Striker.get_vx()==0.0f && Striker.get_vy()==0.0f)
//        {
//            play=2;
//        }
//    }
//
//    if(Striker.get_x() + Striker.get_radius() > inner_box_len/2 || Striker.get_x() - Striker.get_radius() < -inner_box_len/2)
//        Striker.set_vx(Striker.get_vx()*-1);
//    if(Striker.get_y() + Striker.get_radius() > inner_box_len/2 || Striker.get_y() - Striker.get_radius() < -inner_box_len/2)
//        Striker.set_vy(Striker.get_vy()*-1);
//
//    // Update position of ball
//    Striker.set_x(Striker.get_vx()+Striker.get_x());
//    Striker.set_y(Striker.get_vy()+Striker.get_y());
//
//    glutTimerFunc(10, update, 0);
//}
//
//void drawBox(float len) {
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glBegin(GL_QUADS);
//    glVertex2f(-len / 2, -len / 2);
//    glVertex2f(len / 2, -len / 2);
//    glVertex2f(len / 2, len / 2);
//    glVertex2f(-len / 2, len / 2);
//    glEnd();
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//}
//
//void drawBox_hollow(float len) {
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glBegin(GL_QUADS);
//    glVertex2f(-len / 2, -len / 2);
//    glVertex2f(len / 2, -len / 2);
//    glVertex2f(len / 2, len / 2);
//    glVertex2f(-len / 2, len / 2);
//    glEnd();
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//}
//void drawHoles(float rad,float x,float y) {
//
//   glBegin(GL_TRIANGLE_FAN);
//   for(int i=0 ; i<360 ; i++) {
//       glVertex2f(x+(rad * cos(DEG2RAD(i))), y+(rad * sin(DEG2RAD(i))));
//   }
//   glEnd();
//}
//
//void drawBall_hollow(float rad,float x,float y) {
//
//   glBegin(GL_POLYGON);
//   for(int i=0 ; i<360 ; i++) {
//       glVertex2f(x+(rad * cos(DEG2RAD(i))), y+(rad * sin(DEG2RAD(i))));
//   }
//   glEnd();
//}
//
//// Initializing some openGL 3D rendering options
//void initRendering() {
//
//    //glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
//    glEnable(GL_COLOR_MATERIAL);    // Enable coloring
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color
//}
//
//// Function called when the window is resized
//void handleResize(int w, int h) {
//
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void hover_move_right()
//{
//    if(play==1)
//        return;
//    float num = (hover_y - (Striker.get_y()+Striker.get_radius()));
//    float den = (hover_x - (Striker.get_x()+Striker.get_radius()));
//    float tanang = (float)num/(float)den;
//    float ang = atan((double)tanang);
//    if(RAD2DEG(ang)<0)
//        (ang+=DEG2RAD(180));
//    //coutf<<RAD2DEG(ang)<<endl;
//    if(RAD2DEG(ang)-1.0f>0)
//    {
//        hover_rot = -1.0f;
//        hover_x -= Striker.get_x();
//        hover_y -= Striker.get_y();
//        hover_x = ROTATEX(hover_x,hover_y,hover_rot);
//        hover_y = ROTATEY(hover_x,hover_y,hover_rot);
//        hover_x += Striker.get_x();
//        hover_y += Striker.get_y();
//    }
//}
//
//void hover_move_left()
//{
//    if(play==1)
//        return;
//    float num = (hover_y - (Striker.get_y()+Striker.get_radius()));
//    float den = (hover_x - (Striker.get_x()+Striker.get_radius()));
//    float tanang = (float)num/(float)den;
//    float ang = atan((double)tanang);
//    if(RAD2DEG(ang)<0)
//        (ang+=DEG2RAD(180));
//    //cout<<RAD2DEG(ang)<<endl;
//    if(RAD2DEG(ang)+1.0f<180)
//    {
//        hover_rot = 1.0f;
//        hover_x -= Striker.get_x();
//        hover_y -= Striker.get_y();
//        hover_x = ROTATEX(hover_x,hover_y,hover_rot);
//        hover_y = ROTATEY(hover_x,hover_y,hover_rot);
//        hover_x += Striker.get_x();
//        hover_y += Striker.get_y();
//    }
//}
//
//void Striker_move(int dir)
//{
//    if(play==0)
//    {
//        if((Striker.get_x()+Striker.get_radius()<=50.8f && dir==1) || (Striker.get_x()-Striker.get_radius()>=(-50.8f) && dir==-1))
//        {
//            Striker.set_x(Striker.get_x()+(0.3f*dir));
//            hover_x += (0.3f*dir);
//        }
//    }
//}
//
//void handleKeypress1(unsigned char key, int x, int y) {
//
//    if (key == 27) {
//        exit(0);     // escape key is pressed
//    }
//    if(key==13 && play==2)
//        reset_new_chance();
//    if(key==32 && play==0)
//    {
//        display_hover = 0;
//        float num = (hover_y - Striker.get_y());
//        float den = (hover_x - Striker.get_x());
//        float tanang = (float)num/(float)den;
//        float ang = atan((double)tanang);
//        if(ang<0)
//            ang-=DEG2RAD(180);
//        Striker.set_vx(((float)(power+40)/(float)40)*cos(ang));
//        Striker.set_vy(((float)(power+40)/(float)40)*sin(ang));
//        play = 1;
//        //Striker.set_x(hover_x);
//        //Striker.set_y(hover_y);
//    }
//    if (key == 67 || key == 99)
//    {
//        hover_move_right();
//    }
//    if (key == 65 || key == 97)
//    {
//        hover_move_left();
//    }
//
//}
//
//void handleKeypress2(int key, int x, int y) {
//
//    if(key == GLUT_KEY_LEFT)
//    {
//        Striker_move(-1);
//        Striker_move(-1);
//    }
//    if(key == GLUT_KEY_RIGHT)
//    {
//        Striker_move(1);
//        Striker_move(1);
//    }
//    if (key == GLUT_KEY_UP)
//    {
//        if(power < 35 && play==0)
//        {
//            power += 5.0f;
//        }
//    }
//    if (key == GLUT_KEY_DOWN)
//        if(power > -35 && play==0)
//        {
//            power -= 5.0f;
//        }
//}
//
//int isRightClicked = 0;
//int isLeftClicked = 0;
//int drag_on_left = 0;
//int drag_on_right = 0;
//int just_closed = 0;
//int position[2];
//
//void handleMouseclick(int button, int state, int x, int y) {
//
//    if (button == GLUT_RIGHT_BUTTON)
//        isRightClicked = (!state);
//    if (button == GLUT_LEFT_BUTTON && state == 0)
//    {
//        position[0] = x;
//        position[1] = y;
//        //cout<<x<<y<<endl;
//    }
//    if (button == GLUT_LEFT_BUTTON && state == 1)//mauttttttttttttttttt
//    {
//        float num = ((position[1]) - Striker.get_y());
//        float den = ((position[0]) - Striker.get_x());
//        float tanang = (float)num/(float)den;
//        float ang = atan((double)tanang);
//        if(ang<0)
//            ang-=DEG2RAD(180);
//        hover_x = ROTATEX(hover_x,hover_y,RAD2DEG(ang));
//        hover_y = ROTATEY(hover_x,hover_y,RAD2DEG(ang));
//    }
//    if(isRightClicked)
//        drag_on_right = 1 ;
//}
//int position_drag[2]; //to check left or right
//int position_drag_initial[2]; // intensity
//int direction=0;
//void handleMotionClick(int x,int y)
//{
//    if(drag_on_right)
//    {
//        if(position_drag[0]>x)
//        {
//            if(direction!=-1)
//            {
//                position_drag_initial[0]=x;
//            }
//            direction=-1;
//            for(int i=-1;i<(position_drag_initial[0]-x)/100;i++)
//            {
//                Striker_move(-1);
//            }
//        }
//        if(position_drag[0]<x)
//        {
//            if(direction!=1)
//            {
//                position_drag_initial[0]=x;
//            }
//            direction=1;
//            for(int i=-1;i<(x-position_drag_initial[0])/100;i++)
//            {
//                Striker_move(1);
//            }
//        }
//        position_drag[0]=x;
//    }
//}
//
