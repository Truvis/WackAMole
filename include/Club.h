#ifndef CLUB_H
#define CLUB_H

#include "Sprite.h"

class Team;
class Hits;
class Club : public Sprite
{
    public:
        Club(Cell*cell=0,Hits*hits=0,Team*team=0);
        virtual~Club()
        {}

        virtual void Play(Area&area); // each Sprite may have its own logic here

    protected:
        Hits *hits;
        Team *team;
};

#endif // CLUB_H
