#ifndef MOLECONTROLLER_H
#define MOLECONTROLLER_H
#include "Mole.h"
#include "Team.h"

class MoleController : public Mole
{
    public:
        MoleController(Cell*cell=0, int Above=3, int Below=2, Team*team=0, int MOLES=0);
        virtual ~MoleController();
        virtual void Play(Area&area);

    protected:
        Team*team;
        int MOLES;
        int CurrentMoles;

    private:
};

#endif // MOLECONTROLLER_H
