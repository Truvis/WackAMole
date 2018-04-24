#include <iostream>

#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>

#include "Mask.h"
#include "Page.h"

void enable_raw_mode() {
    termios term;
    tcgetattr(0, &term);
    term.c_lflag&= ~(ICANON | ECHO);
    tcsetattr(0,  TCSANOW, &term);
}

void disable_raw_mode() {
    termios term;
    tcgetattr(0, &term);
    term.c_lflag|= ICANON | ECHO;
    tcsetattr(0,  TCSANOW, &term);
}

bool kbhit() {
    int bytesWaiting;
    ioctl(0, FIONREAD, &bytesWaiting);
    return bytesWaiting>0;
}


Page::Page(int  high,  int  wide,  int  cellHigh,  int cellWide)
    : rows(cellHigh*high), cols(wide*cellWide)
    , cellHigh(cellHigh) , cellWide(cellWide)
{
    enable_raw_mode();
    erase();
}

Page::~Page() {
    erase();
    disable_raw_mode();
    Emit(CSI "?25h");
}

void Page::erase() {
         Emit( CSI "H"  CSI "K" CSI "?25l");
     for(int  down=1; down<rows; down++)
         Emit( CSI "1B" CSI "K");
}

int   Page::Read() {
    if (!kbhit()) return 0;     // no key has been typed at this instance

    int   read =  getchar();    // first key awaiting is used          down 27 91 66   up 27 91 65   left 27 91 68  right 27 91 67  h=104  j=106 k=107 l=108 m=109
    if (  read == 27 ) {        // if arrow key we read past its two lead keys ESC[
          read =  getchar();
          if (read==91) read = getchar();
          switch (read) {
              case 65: read='k'; break;
              case 66: read='j'; break;
              case 67: read='l'; break;
              case 68: read='h'; break;
          }
    }
   tcflush(0,TCIFLUSH);        // if user had type-ahead it is tossed
   return read;
}

void Page::Emit(Char byte) { if (byte)              putchar( byte ); }

void Page::Emit(Char*text) { if (text) while(*text) putchar(*text++); }







======================


bool Club::Move(screen&local, int _key) {
    bool hits   =false;
    int uponOver=over;      // hold onto where you were so
    int uponDown=down;      // you can redraw whats under

    switch(_key) {
         case 'h': shift(local,-1);     //LEFT
            break;
         case 'j': shift(local,0,1);    //DOWN
            break;
         case 'k': shift(local,0,-1);   //UP
            break;
         case 'l': shift(local,1);      //RIGHT
            break;
         case ' ': hits=true;
            break;
    }
    local.Draw(uponOver,uponDown);
    paint(local);
    return hits;
}
















