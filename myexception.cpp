#include "myexception.h"
#include <string.h>

myException::myException()
{

}

myException::myException(const char* str_)
{
    strcpy(str,str_);
}

const char* myException::getMessage() {
    return str;
}
