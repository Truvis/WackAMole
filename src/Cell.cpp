#include "Cell.h"
#include "Area.h"

#include "Mask.h"
static
Char*TURF = HUE(32,42)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CLR;

Cell::Cell(int row,   int col, Char*site) : down(row), over(col)  {
    seen=false;             // the cell has not yet been shown
    show[SITE]=site;        // site was made for us so we must delete it
    show[CELL]=TURF;        // static so system deletes[]
}

Char*Cell::Have(SLOT slot) { return (show[slot]); }

void Cell::Show(SLOT slot, Char*ansi) {
     show[slot]=ansi; // slot/layer ANSI code text.
     seen=false;
}

void Cell::Show(Area*area) {
    if (!seen) {
         Char*site= show[SITE];
         for(int  slot=1+SITE;slot<LAST; ++slot) {
            Char *ansi=  show[slot];
            if ( !ansi)  continue;      // paint only the layers that are set
            area->Emit(site);           // place the brush back to [0,0] of cell
            area->Emit(ansi);
         }
         seen=true;
    }
}


