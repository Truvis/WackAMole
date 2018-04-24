#include "Club.h"
#include "Hits.h"
#include "Cell.h"
#include "Team.h"
#include "Mole.h"
#include "Mask.h"
static
Char *BASH = HUE(30,41)
"          " CR(10)
"______    " CR(10)
"\\    /    " CR(10)
" |==|     " CR(10)
" |||||||||" CR(10)
" |==|     " CR(10)
"/____\\    " CR(10)
"          " CLR;
static
Char *HOLD = HUE(40,42)
"______    " CR(10)
"\\    /    " CR(10)
" |==|     " CR(10)
" |||||||||" CR(10)
" |==|     " CR(10)
"/____\\    " CR(10)
"          " CR(10)
"          " CLR;
static
Char *OVER = HUE(31,40)
"______    " CR(10)
"\\    /    " CR(10)
" |==|     " CR(10)
" |||||||||" CR(10)
" |==|     " CR(10)
"/____\\    " CR(10)
"          " CR(10)
"          " CLR;

void Club::Play(Area&area) {
    // get our keys by reading from out area
    int key=area.Read();

    // create a new cell that will be used to show the movement
    // and then
    Cell* ClubCell;

    // do we have a key?
    if(key){
        switch(key){
            case 'i':
                // move up
                    ClubCell=area.Move(cell,-1,0);
                break;
            case 'j':
                // move left
                    ClubCell=area.Move(cell,0,-1);
                break;
            case 'k':
                // move down
                    ClubCell=area.Move(cell,1,0);
                break;
            case 'l':
                // move right
                    ClubCell=area.Move(cell,0,1);
                break;
            case ' ':
                // hit mole
                    Show(BASH);
                    // Increase hits
                    if(cell->Have(MOLE)){
                        // up hits
                        hits->Gain();
                        // return the mole if the mole is found
                        // in a cell.
                        Mole*mole = team->FindMole(cell);
                        // check for mole then hide mole
                        if(mole){mole->Hide();}
                    }
                    return;
                break;
            default:

                return;
        }
        // show the new cell after the move.
        Upon(ClubCell);
        if(cell->Have(MOLE)){
              Show(OVER);
        }
        else{
            // show the original content
            Show(HOLD);
        }
    }

}


Club::Club(Cell*cell, Hits*hits, Team*team)
    : Sprite(CLUB,cell),hits(hits),team(team){
    Show(HOLD);
}
