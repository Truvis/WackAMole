#include <unistd.h> // usleep
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

Tock::Tock(Cell*upon, int game, int waitm) : Sprite(MOLE,upon), game(game), wait(waitm*1000)
{
     //wait*=1000;
     ratiof = wait/1000000.0;
     ticks=s2t(game);
     upon->Show(CELL, 0 );                  // shut off CELL layer; keeps club from moving over us
     upon->Show(HOLE, TOCK);                // setting hole keeps the holes away
     mask = new Mask( TICK, '#', "%5d" );   // we cover/write the number over the ###..
     upon->Show(MOLE, mask->Face(t2s(ticks)));   // setting mole keeps the moles away
     sleep = (int)(wait*.99); // 1% idle time factor to get as close as possible to 60 seconds.
}

void Tock::Play(Area&area) { --ticks;Show(mask->Face(t2s(ticks))); }


bool Tock::Ticks() { if (ticks) usleep(sleep); return (ticks); }

// used to return seconds
int Tock::s2t(int seconds){
    return (int)(seconds/ratiof);
}

int Tock::t2s(int ticks){
    return (int)(ticks*ratiof);
}
