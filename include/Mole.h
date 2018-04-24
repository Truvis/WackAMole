#ifndef MOLE_H
#define MOLE_H

#include "Sprite.h"


class Mole : public Sprite
{
    public:
        // Above:
        // Below:
        Mole(Cell*cell=0, int Above=3, int Below=2);
        virtual ~Mole()
        {}

        virtual void Play(Area &area);

        void Hide();

    protected:
        int Above;
        int Below;
        bool Seen;
        int Ticks;

        static int CurrentMoles;
};

#endif // MOLE_H
