#ifndef FAIL_H
#define FAIL_H

typedef const char  Char;
#define SET(_n_,_i_)    static const int _n_=(_i_)

class Fail
{
    public:
        Fail(Char* form, ... );
virtual~Fail()
        {}
};

#endif // FAIL_H
