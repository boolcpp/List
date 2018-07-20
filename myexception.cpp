#include "myexception.h"
#include <string.h>

myException::myException()
{
    str[0]=0;   //strcpy(str,"");
}

myException::myException(const char* str_, int strnum_)
{
    if (str_ == nullptr)
    {
        str[0]=0;
    }
    else {
        strcpy(str,str_);
    }
    strnum = strnum_;
}

const char* myException::getMessage() {
    if (str[0]==0)
        return "Unknown exception";
    return str;
}

int myException::getStrnum() {
    return strnum;
}
