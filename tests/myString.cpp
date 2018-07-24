#include "myString.h"
#include <string.h>

myString::myString()
{
    buf = new char [1];
    buf[0] = 0;
    len = 0;
}

myString::myString(myString &src)
{
    len = src.len;
    buf = new char[len + 1];
    strcpy(buf, src.buf);
}

myString::myString(myString&& src)
{
    len = src.len;
    buf = src.buf;
    src.buf = nullptr;
}

myString::~myString()
{
    if(buf != nullptr)
    {
        delete [] buf;
    }
}
