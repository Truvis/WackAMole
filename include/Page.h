#ifndef PAGE_H
#define PAGE_H

#include "Fail.h"

#define      _KEY(_key_)     ((1<<8)|_key_)

class Page                      // manages the reading and writing to console page
{
    public:
        Page(int high, int wide, int cellHigh, int cellWide);
virtual~Page();

    protected:
        int   rows;             /// console rows(down) cols(over)
        int   cols;
        int   cellHigh;
        int   cellWide;

    public:

        void  erase();
        int   Read();

        void  Emit(Char byte);
        void  Emit(Char*text);
};

#endif // PAGE_H
