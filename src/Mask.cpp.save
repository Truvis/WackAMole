#include <stdio.h>      // snprintf
#include <string.h>     // strcpy

#include "Mask.h"

Mask::Mask(Char*upon, Char find, Char*form)
{
     if(!upon||!*upon) Fail("Mask: requires input");    // ensure we got something to work
     copy = strcpy( new char[strlen(upon)+1] , upon );    // we leave theirs alone make a copy
     spot = strchr(copy,find);                          // find the char becomes the spot
     if(!spot) Fail("Mask: did not find[%c]",find);     // the spot is where we will write
     this->form=form;                                   // we keep their form
}

Mask::~Mask()
{
    delete copy; copy=0;                                // we made a copy its ours to free
}

Char*Mask::Face(int numb) {                             // fills the spot with number
    char mine[24];
    int wide=sprintf(mine,form,numb);
    memcpy(spot,mine,wide);                             // don't write the tail '\0'
    return copy;
}


Char*Mask::Site(int down, int over) {                   // places the cursor on row,col
    char   *hued=new char[24];
    sprintf(hued,"%s%d;%dH",CSI,down+1,over+1);         // CSI n ; m H
    return  hued;
}
