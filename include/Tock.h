#ifndef TOCK_H
#define TOCK_H

#include "Sprite.h"

class Mask;

class Tock : public Sprite
{
    public:
        Tock(Cell*upon, int game, int wait);
        virtual~Tock() {}

        virtual void Play(Area&area);
        bool Ticks();
        int s2t(int seconds);
        int t2s(int ticks);

    protected:
        int  game;
        int  wait;
        int  ticks;
        Mask*mask;
        double ratiof;
        int sleep;
};

#endif // TOCK_H
