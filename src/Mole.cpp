#include "Mask.h"
#include "Mole.h"
static
Char *MMOLE = HUE(31,40)
"XXXXXXXXXX" CR(10)
"X        X" CR(10)
"X ^._.^  X" CR(10)
"X  (=)   X" CR(10)
"X  (=)   X" CR(10)
"X  ===   X" CR(10)
"X        X" CR(10)
"XXXXXXXXXX" CLR;

void Mole::Play(Area&area) {
    // logic loop for showing and hiding the mole
    // show mole in hole then hide the mole in the hole.
    // reduce ticks
    --Ticks;
    // if we hit 0 ticks then the mole needs to be hid or seen
    if(Ticks==0) {
        // if mole is visible hide mole
        if(Seen){
            // call our globally used method for hiding moles
            Hide();
        } // otherwise show mole
        else {
            Seen=true;
            Ticks=Above;
            Show(MMOLE);
        }
    }
}

Mole::Mole(Cell*cell, int Above, int Below)
        : Sprite(MOLE,cell), Above(Above), Below(Below) {
    Show(MMOLE);
    Seen = true;
    Ticks = Above;
}

void Mole::Hide(){
    Seen=false;
    Ticks=Below;
    Show(0);
}
