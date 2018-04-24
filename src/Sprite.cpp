#include "Sprite.h"
#include "Cell.h"

void Sprite::Show(Char *form) {
     if (cell)  cell->Show(slot,form);  // if the caller is on a cell tell it to show
}

void Sprite::Upon(Cell *upon) {           // places Sprite upon a cell
     //if (cell)  cell->Show(slot, 0);    // tell old cell to no-show me anymore
     Show(0);
     cell= upon;
}

// check to see if the slow and the cell are the same.
// if so return back with we are. otherwise 0 for nope.
Sprite* Sprite::Like(SLOT wantslot,Cell*wantcell){
    if((wantslot==slot) && (wantcell==cell)){
        return this;
    }
    else {
        return 0;
    }
}
