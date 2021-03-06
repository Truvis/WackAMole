#include <iostream> // cerr
#include <stdio.h>
#include <stdarg.h> // allows for ...
using namespace std;

#include "Fail.h"

Fail:: Fail(Char* form, ... ) {
    char line[1024];
    va_list   args;
    va_start (args, form);
    vsprintf (line, form, args);
    va_end   (args);
cerr<<"ERR:"<<line<<endl;
  throw(Char*)line;
}

// Example:
// if(bad) Fail("Task-x: reading:[%s] found [%d] bad things", text, many);
