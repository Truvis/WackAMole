#include <iostream>
#include <string.h>

// LINUX //



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





// WINDOWS //
/*#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "Mask.h"

HANDLE  EMIT;
DWORD   OrigEmitMode=0;         // original mode is kept so we can reinstate on exit
#define ENABLE_VIRTUAL_TERMINAL 0x0004
HANDLE  READ;
DWORD   OrigReadMode=0;         // original mode is kept so we can reinstate on exit

typedef const char Char;

VOID Orig () {
    printf(CSI "0m");
    SetConsoleMode(EMIT, OrigEmitMode);
    SetConsoleMode(READ, OrigReadMode);
}
VOID Fail (Char*failMessage)
{
    fprintf(  stderr,   "\nFail:\n\t%s\n<QUIT>\n", failMessage);
    Orig();
    ExitProcess(0);
}

#include "Page.h"

Page::Page(int high, int wide, int cellHigh, int cellWide)
    : rows(cellHigh*high), cols(wide*cellWide), cellHigh(cellHigh), cellWide(cellWide)
{
/// READ
    if (INVALID_HANDLE_VALUE == (READ = GetStdHandle(STD_INPUT_HANDLE )))
        Fail("Couldn't get the console input handle!");

    if (!GetConsoleMode(READ, &OrigReadMode))
        Fail("Couldn't get the console input  Mode!");

/// EMIT
    if (INVALID_HANDLE_VALUE == (EMIT = GetStdHandle(STD_OUTPUT_HANDLE)))
        Fail("Couldn't get the console output handle!");

    if (!GetConsoleMode(EMIT, &OrigEmitMode))
        Fail("Couldn't get the console output  Mode!");

/// SETS
    if (!SetConsoleMode(EMIT, OrigEmitMode | ENABLE_VIRTUAL_TERMINAL))
        Fail("Couldn't set the console output  Mode!");

    if (!SetConsoleMode(READ, ENABLE_WINDOW_INPUT))  // | ENABLE_MOUSE_INPUT;
        Fail("Couldn't set the console  input  Mode!");

    CONSOLE_CURSOR_INFO cursor;     // we do not want to see the blinking cursor
    cursor.dwSize   = 1;
    cursor.bVisible = false;
    SetConsoleCursorInfo(EMIT, &cursor);
}

Page::~Page()
{
    erase();
    Orig();
}

void Page::erase() {
         Emit( CSI "H"  CSI "K" CSI "?25l");
     for(int  down=1; down<rows; down++)
         Emit( CSI "1B" CSI "K");
}

int   Page::Read() {
    if (!kbhit()) return 0;     // no key has been typed at this instance

    int   read =  getch();      // first key awaiting is used
    if (  read == 224 ) {       // if special we read its distinction
          read =  getch();
          read = _KEY(read);    // add special mark: set a high bit
    }
    while(kbhit())getch();      // if user had type-ahead it is tossed
   return read;
}

void Page::Emit(Char byte) { if (byte)              putchar( byte ); }
void Page::Emit(Char*text) { if (text) while(*text) putchar(*text++); }*/
























