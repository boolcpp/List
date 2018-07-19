#ifndef EXOUTOFRANGE_H
#define EXOUTOFRANGE_H
#include "myexception.h"

class exOutOfRange : public myException
{
    char *msg;
public:
    exOutOfRange();
};

#endif // EXOUTOFRANGE_H
