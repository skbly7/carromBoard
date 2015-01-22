#ifndef OBJECT_H
#define OBJECT_H
class Object {
    protected :
        float __mass;
        float __vx,__vy;
        float __x,__y;
        float __r, __g, __b;
        float __mu = 0.004f;
    public :
        float getvx();
        virtual void setId(int);
        virtual int getId();
        float getvy();
        float xpos();
        virtual bool notPocketed();
        bool isCollided(Object *b);
        void collided(Object *b);
        float ypos();
        void apply_friction(int);
        float mass();
        virtual void pocketted();
        virtual void position();
        virtual void rgb(float,float,float);
        virtual void radius(float);
        virtual float radius();
        virtual void draw();
        virtual void debug();
        void debug_coin();
    //Setting values
        void setvx(float x);
        void setvy(float y);
        void update_location(int);
        virtual float gradius();
        void mass(float m);
        void v(float x,float y);
        bool stopped();
        void position(float x,float y);
};

#endif // OBJECT_H
