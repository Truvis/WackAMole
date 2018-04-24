#include "Team.h"
#include "Mole.h"
#include "Sprite.h"
#include "Flip.h"

Team::~Team()
{
    for(Sprite* Sprite: team)
       delete Sprite;
}

void Team::Play(Area&area) {
    for(Sprite* Sprite: team)
        Sprite->Play (area);
}

Team&Team::Keep(Sprite*Sprite) {

    team.push_back(Sprite); return *this;

}

Mole* Team::FindMole(Cell*molecell)
{
    // start the loop for looping Sprite to check for mole
    for(Sprite* Sprite: team)
        // does Sprite contain a mole in that cell?
        if(Sprite->Like(MOLE,molecell))
            // return Sprite as a mole.
            return (Mole*)Sprite;
    return 0;
}
