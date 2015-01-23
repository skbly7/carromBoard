#ifndef CORNER_H
#define CORNER_H
#include <Coin.h>


class Corner : public Coin
{
    public:
        Corner();
        void shadow();
        void draw();
        virtual ~Corner();
    protected:
    private:
};

#endif // CORNER_H
