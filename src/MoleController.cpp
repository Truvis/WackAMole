#include "MoleController.h"
#include "Area.h"
#include "Mask.h"
#include "Mole.h"
class Team;

MoleController::MoleController(Cell*cell, int Above, int Below, Team* team, int MOLES)
        : Mole(cell,Above,Below),team(team),MOLES(MOLES) {

        // mole counting. i am the first one.
    CurrentMoles=1;
    if(team==0) {
        Fail("Team(expects but returned with 0)");
    }
}

MoleController::~MoleController()
{
    //dtor
}

// reposition mole after removing
void MoleController::Play(Area&area) {
    Mole::Play(area);
    // use current mole
    if(CurrentMoles<MOLES){
        // find
        Cell* place = area.FindingRandomly(HOLE,MOLE);
        // does a hole have a mole?
        if(place){  // this place  which is a hole that can have mole
            //
            Mole* remole = team->FindMole(0); // put the mole in a hole.
            // add mole to a hole after being hidden
            if(remole){
                remole->Upon(place); // put the mole in a hole without creating a new mole in memory
            }
            else {
                team->Keep(new Mole(place,Above,Below)); // create out initial moles in memory
            }
            CurrentMoles++;     // adding another mole
        }
    }
}


