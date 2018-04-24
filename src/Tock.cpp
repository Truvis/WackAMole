#include "Tock.h"
#include "Area.h"
#include "Cell.h"

#include "Mask.h"
static
Char*TOCK = HUE(31,47)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CR(10)
"          " CLR;
static
Char*TICK = HUE(31,47) LF LF LF
            HOP(3)"#####"  CLR;

Tock::Tock(Cell*upon, int game, int wait) : Sprite(MOLE,upon), game(game), wait(wait*1000)
{
     //wait*=1000;
     ticks=s2t(game);
     upon->Show(CELL, 0 );                  // shut off CELL layer; keeps club from moving over us
     upon->Show(HOLE, TOCK);                // setting hole keeps the holes away
     mask = new Mask( TICK, '#', "%5d" );   // we cover/write the number over the ###..
     upon->Show(MOLE, mask->Face(ticks*wait/1000000));   // setting mole keeps the moles away
}

void Tock::Play(Area&area) { --ticks;Show(mask->Face(ticks*wait/1000000)); }

//#include <windows.h>    // Sleep
#include <unistd.h> // usleep

bool Tock::Ticks() { if (ticks) usleep(wait); return (ticks); }

// used to return seconds
int Tock::s2t(int seconds){
    return seconds*1000000/wait;
}
