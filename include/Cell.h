#ifndef CELL_H
#define CELL_H

#include <Sprite.h>

class Area;

class Cell
{
    public:
        Cell(int row, int col, Char*site);
virtual~Cell() { delete show[SITE]; }

        Char*Have(SLOT slot);               // does this cell have that slot set?
        void Show(SLOT slot, Char*ansi);    // registers a thing to be shown
        void Show(Area*area);               // actual presentation happens with this
        // Provide a bridge to access private information
        // without exposing the protected variables.
        int Down(){return down;}
        int Over(){return over;}

    protected:
        int  down;                          // where this cell is on the Area
        int  over;
        bool seen;                          // flag: we have been shown; or NOT
        Char*show[LAST]{0};                 // ordered layers we show when set
};

#endif // CELL_H
