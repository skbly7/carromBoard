#ifndef UTILITY_H
#define UTILITY_H


class Utility
{
    public:
        Utility();
        virtual ~Utility();
        void filled_rectangle(float,float,float,float,float,float,float,float,float,float,float);
        void filled_top_given(float,float,float,float,float,float);
        void filled_circle(float,float,float,float,float,float);
        void empty_circle(float,float,float,float,float,float);
        void incomplete_circle(float,float,float,float,float,float,float);
        float to_radian(float);
        float rotatex(float,float,float);
        void write_text(float,float,float,float,float,int,char *str);
        float rotatey(float,float,float);
        void draw_triangle(float,float,float,float,float,float,float,float,float);
        void draw_rotate_triangle(float,float,float,float,float,float,float,float,float,float,float,float,float);
        void draw_line(float,float,float,float,float,float,float);
};

#endif // UTILITY_H
