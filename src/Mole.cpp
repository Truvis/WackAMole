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

int Mole::CurrentMoles = 0;

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
        else { // make yourself shown.
            Seen=true;
            Ticks=Above; // reset above timer that mole should stay above.
            Show(MMOLE); // show the above mole picture.
        }
    }
}

Mole::Mole(Cell*cell, int Above, int Below)
        : Sprite(MOLE,cell), Above(Above), Below(Below) {
        // start mole in up mode
    Show(MMOLE);
    Seen = true; // reset above timer that mole should stay above.
    Ticks = Above; // show the above mole picture.
}

void Mole::Hide(){
    Seen=false;
    Ticks=Below;
    // remove the mole
    Upon(0);
    // set current mole count down to recyle mole in memory
    --CurrentMoles;
}
