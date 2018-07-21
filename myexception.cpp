#include "myexception.h"
#include <string.h>

myException::myException()
{
    str[0]=0;   //strcpy(str,"");
}

myException::myException(const char* str_, int strNumber_)
{
    if (str_ == nullptr)
    {
        str[0] = 0;
    }
    else
    {
        strcpy(str,str_);
    }
    strNumber = strNumber_;
}

const char* myException::getMessage() {
    if (str[0] == 0)
    {
        return "Unknown exception";
    }
    return str;
}

int myException::getStrNum() {
    return strNumber;
}
