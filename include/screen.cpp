
/* this class is used to manage the state of what is displayed
on the screen. At any point in time, this data structure maintains
the computer's "view" of what is displayed */
#include <iostream>
#include <unistd.h>
#include <curses.h>

using namespace std;

class screen
  // two dimensional array of characters that maps to the screen
{
private:
  char screenpos[80][24];

public:

  explicit screen()  // this the constructor for this class
  {
    int x,y;
    for (y=0;y!=24;y++)  // set all of the characters to spaces initially
      for(x=0;x!=80;x++)
	screenpos[x][y]=' ';


/*    WINDOW *w = initscr(); // initialize screen for curses
    cbreak();
    nodelay(w, TRUE);
    initscr();
    noecho();  // this turns off local key echos
    curs_set(0); // makes the cursor invisible*/
  }
  // this method allows an external function to place a character
  // within the screen matrix
  void placechar(int x, int y, char symbol)
  {
    screenpos[x][y]=symbol;
  }

  // this method actually draws the screen using curses
  void display()
  {
    int y,x;  // it cycles through the two dimensional array and
              // puts the characters in the appropriate spots on the screen
    for (y=23; y!=-1; y--)
      {
	for (x=0; x!=80; x++)
	  {
	    //move(y,x); // curses function
	    //printw("%c", screenpos[x][y]);
	    //cout.flush(); // flush the output buffers  -- may be unnecessary
	  }
      }
    refresh();  // required to update the screen
  }
};
