#include "Hits.h"
#include "Area.h"
#include "Cell.h"

#include "Mask.h"

static
Char*HUNT = HUE(30,47)
            "          " CR(10)
            "          " CR(10)
            "          " CR(10)
            "          " CR(10)
            "          " CR(10)
            "          " CR(10)
            "          " CR(10)
            "          " CLR;

// dirty hack on making
static
Char*HITS = HUE(31,47) LF LF LF
            HOP(3)"#####"  CLR;

Hits::Hits(Cell*upon): Sprite(MOLE,upon), hits(0)
{
     upon->Show(CELL, 0 );                  // shut off CELL layer; keeps club from moving over us
     upon->Show(HOLE, HUNT);                // setting hole keeps the holes away
     mask = new Mask( HITS, '#', "%5d" );   // we will write (cover) the # number signs with Mask
     upon->Show(MOLE, mask->Face( hits));   // setting mole keeps the moles away
}

void Hits::Play(Area&area) {
    Show(mask->Face(hits)); // updating the clock face
}

// gain method for upping hits
void Hits::Gain() {
    ++hits; //gain on mole wack
}

int Hits::getHits(){
    return hits; // get the hits for score keeping.
}
