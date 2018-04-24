#ifndef Sprite_H
#define Sprite_H

#include "Area.h"
#include "Slot.h"
class Cell;



class Sprite
{
    public:
        Sprite(SLOT slot, Cell*upon=0) : slot(slot), cell(upon) {}
virtual~Sprite() {}

virtual void Play(Area&area) =0;            // each Sprite may have its own move logic here

        void Show(Char*form);               // informs the cell to show itself with my form
        void Upon(Cell*cell);               // places the Sprite upon a specific cell
        Sprite* Like(SLOT,Cell*cell=0);

    protected:
        SLOT slot;                          // the Sprite form lives on a cell level
        Cell*cell;                          // the current cell this Sprite is upon
};

#endif // Sprite_H
