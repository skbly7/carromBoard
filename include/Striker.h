#ifndef STRIKER_H
#define STRIKER_H

#include <Coin.h>


class Striker : public Coin
{
    public:
        Striker();
        virtual ~Striker();
        void draw();
        void shoot();
        void move_left();
        void move_right();
        void create_line(float,float);
        void limit(float);
        void rotate_left();
        void rotate_right();
        void increase_power();
        void decrease_power();
    protected:
    private:
        float length,angle;
        float strip=0.05f,max_width;
};

#endif // STRIKER_H
