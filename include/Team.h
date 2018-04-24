#ifndef TEAM_H
#define TEAM_H

#include <vector>
using namespace std;

#include "Area.h"
#include "Sprite.h"
class Mole;
class Team
{
    public:
        Team() {}
virtual~Team();

        Team&Keep(Sprite*form);           // add a team member to the squad
        void Play(Area&area);           // plays team members on the arena

        Mole* FindMole(Cell*cell);

    protected:
        vector<Sprite*>  team;
};
#endif // TEAM_H
