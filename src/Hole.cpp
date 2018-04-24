#include "Mask.h"
#include "Hole.h"
static
Char *MHOLE = HUE(91,43)
"XXXXXXXXXX" CR(10)
"X        X" CR(10)
"X        X" CR(10)
"X        X" CR(10)
"X        X" CR(10)
"X        X" CR(10)
"X        X" CR(10)
"XXXXXXXXXX" CLR;

void Hole::Play(Area&area) {

}

Hole::Hole(Cell*cell) : Sprite(HOLE,cell){
    Show(MHOLE);
}

