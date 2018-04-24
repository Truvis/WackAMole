#ifndef HITS_H
#define HITS_H

#include "Sprite.h"
#include "Mask.h"

class Hits : public Sprite
{
    public:
        Hits(Cell*upon);
virtual~Hits() {}

virtual void Play(Area&area);
        void Gain();
        int getHits();

    protected:
        int  hits;
        Mask*mask;
};

#endif // HITS_H
