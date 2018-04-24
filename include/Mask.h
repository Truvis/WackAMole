#ifndef MASK_H
#define MASK_H

#include "Fail.h"
//  {usage:}  myForm = HUE(31,47) "ABC" CR(3) "DEF" CLR;
#define CSI         "\x1b["
#define CLR         CSI "0m"            // Clears; at end of work resets ATTRIBUTES
#define LF          CSI "1B"            // Drops down one line
#define CR(n)       CSI#n"D" LF         // carriage return (ready for next line)
#define HOP(n)      CSI#n"C"            // skip over; TRANSPARENT effect
#define HUE(f,b)    CSI#f";"#b"m"       // set FOREGROUND and BACKGROUND

class Mask
{
    public:
        Mask(Char*upon, Char find, Char*form);
virtual~Mask();

        Char*Face(int numb);

 static Char*Site(int down, int over);

    protected:
        char*copy;
        char*spot;
        Char*form;
};

#endif // MASK_H
