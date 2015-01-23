#ifndef WORLD_H
#define WORLD_H
#include <GL/glut.h>
#include "Coin.h"
#include "Board.h"
    class World {
    private :
        static World *instance;
        const static int WINDOW_X_POSITION = 0;
        const static int WINDOW_Y_POSITION = 0;
        int width, height;
        int items_count;
        int taking_options;
        Board *board;
    public :
        ~World();
        World(int,int);
        void start(int argc,char *argv[]);
        void draw();
        void debug_objects();
        void taking_inputs();
        void add_board();
        void options_set(unsigned char,int,int);
        void initRendering();
        void hResize(int,int);
        static void handleResize(int,int);
        static void update(int);
        static void drawEverything();
        static void mouseClick(int,int,int,int);
        static void mouseMotion(int,int);
        static void handleKeypress(unsigned char,int,int);
        static void specialKeypress(int,int,int);
        void drawAll();
    };
#endif
