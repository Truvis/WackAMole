#include "MoleController.h"
#include "Area.h"
#include "Mask.h"
#include "Mole.h"
class Team;

MoleController::MoleController(Cell*cell, int Above, int Below, Team* team, int MOLES)
        : Mole(cell,Above,Below),team(team),MOLES(MOLES) {

    CurrentMoles=1;
    if(team==0) {
        Fail("Team(expects but returned with 0)");
    }
}

MoleController::~MoleController()
{
    //dtor
}

void MoleController::Play(Area&area) {
    Mole::Play(area);
    if(CurrentMoles<=MOLES){
        Cell* cell = area.FindingRandomly(HOLE,MOLE);
        if(cell){
            team->Keep(new Mole(cell,Above,Below));
            CurrentMoles++;
        }
    }
}


