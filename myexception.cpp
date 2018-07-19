#include "myexception.h"
#include <string.h>

myException::myException()
{

}

myException::myException(const char* str_)
{
    if (str_ == nullptr)
    {
        strcpy(str,"Unknown exception!");
    }else {
        strcpy(str,str_);
    }

}

const char* myException::getMessage() {
    return str;
}
