#ifndef BOARD_H
#define BOARD_H
#include "Corner.h"
#include <Coin.h>
#include <Striker.h>
class Board
{
    public:
        Board(float,float);
        virtual ~Board();
        void rgb(float, float, float);
        void drgb(float, float, float);
        void draw();
        void update();
        int foul;
        Corner corner[4];
        Object *items[100];
        Striker *striker;
        int items_count=0;
        void handleKeys(unsigned char,int,int);
        void specialKeys(int,int,int);
        void set_not_required(int);
    protected:
    private:
        int reset=0;
        int score=0;
        int queen=50;
        int not_color_required=4;
        void pocket_coin();
        int processing[100][100];
        void add_striker(float,float,float,float,float,float);
        void place_corners();
        void corner_beautify();
        void draw_coins();
        void main_board();
        void reset_striker();
        void place_striker(float,float);
        void move_coins();
        void check_wall();
        void background_features();
        void draw_corners();
        void striker_area();
        void collision_handle();
        void add_coin(float,float,float,float,float,float,int);
        void add_coins();
        bool isStopped();
        bool isRunning();
        const float corner_sq=0.30f;
        float width,height;
        float s_w,s_h;
        float __r, __g, __b;
        float __dr, __dg, __db;
};

#endif // BOARD_H
