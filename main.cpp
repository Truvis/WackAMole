#include <iostream>
using namespace std;

#include "Area.h"
#include "Team.h"
#include "Tock.h"
#include "Hits.h"
#include "Hole.h"
#include "Mole.h"
#include "Club.h"
#include "Flip.h"
#include "Keep.h"
#include "MoleController.h"

SET(High,  3);  // how many cells high is the arena
SET(Wide,  8);  // how many cells wide is the arena
SET(Down,  8);  // how many letters down is a cell
SET(Over, 10);  // how many letters over is a cell
SET(ABOVE, 3);  // number of moles
SET(BELOW, 2);  // seconds a mole stays up
SET(HOLES, 6);  // how many holes
SET(MOLES, 3);  // set moles
SET(Game, 60);  // how many seconds long is a game
SET(Wait,250);  // how many milliseconds used to throttle the user
SET(MoleFillsHolePercent,55);

int main()
{
  try {

        Keep scores;
        // allow for score access outside of raw mode
        int myscore;

        {   // ENTER RAW MODE   -- confined
            Area area( High,Wide,   Down,Over );            // ARENA: many cells each with girth
            Team team;                                      // keeper of all things that move

            Tock*tock=new Tock(area.Upon(High -1,Wide -1)   // OUR system's time keeper
                              ,Game                         // game clock seconds to play
                              ,Wait);                       // throttles the play
            team.Keep(tock);                                // the clock is our first team member

            Hits*hits=new Hits(area.Upon(High -1,0));       // presents (tracks) whacks
            team.Keep(hits);

            // pass the team memory address so we can look through Sprite
            // and check if a Sprite is a mole
            team.Keep(new Club(area.Upon(High/2,Wide/2),hits, &team));

            // randomly place holes on the area but yet have no moles
            for(int x=0;x<HOLES;x++){
                team.Keep(new Hole(area.FindRandNotHaving(HOLE)));
            }


            team.Keep(new MoleController(area.FindRandHavingHoleNotHavingMole()
                                  ,tock->s2t(ABOVE),tock->s2t(BELOW),&team,MOLES)); //tells mole how long to show/hide

            // loop and create moles placing them on holes.


            do {
                area.Show();                                // each cell that has changed is shown
                team.Play (area);                           // each team member gets her chance to do
            }  while(tock->Ticks());                        // the clock elapsed or it waits some

            myscore = hits->getHits();                      // how well did this player do -- whacks
        }   // removes RAW mode

        scores.SaveScore(myscore);

        return 0;

  } catch(Char*fail) {
      cerr << "ERR: " << fail << endl;
  }
}
