#ifndef HOLE_H
#define HOLE_H

#include <Sprite.h>


class Hole : public Sprite
{
    public:
        Hole(Cell*cell=0);
        virtual ~Hole()
        {}

        virtual void Play(Area &area);

    protected:
};

#endif // HOLE_H
