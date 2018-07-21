#ifndef EXOUTOFRANGE_H
#define EXOUTOFRANGE_H
#include "myexception.h"

class exOutOfRange : public myException
{

public:
    exOutOfRange();
    exOutOfRange(const char *str_,const char *fileName, int lineNumber);
};

#endif // EXOUTOFRANGE_H
