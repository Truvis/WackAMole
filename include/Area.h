#ifndef AREA_H
#define AREA_H

#include "Page.h"
#include "Flip.h"
#include "Slot.h"
class Cell;

class Area : public Page
{
    public:
        Area(int high, int wide, int down, int over);
virtual~Area();

        void Show();    // gives each cell a chance to redraw if needed
        Cell*FindingRandomly(SLOT having, SLOT nothaving);

        Cell*FindRandNotHaving(SLOT nothaving){return FindingRandomly(ZERO,nothaving);}
        Cell*FindRandNotHavingHole(){return FindingRandomly(ZERO,HOLE);}
        Cell*FindRandHavingHoleNotHavingMole(){return FindingRandomly(HOLE,MOLE);}
        Cell*Upon(int row, int col); // the cell at [row,col]
        Cell*Move(Cell*,int y,int x);

    protected:
        int high, wide; // how many cells is the ARENA
        int down, over; // how many letters on a cell
        Cell  *** area; // the arena of play (matrix)
        Roll rollHigh{high};
        Roll rollWide{wide};
    private:
        static const int TRYS = 50;
};

#endif // AREA_H
