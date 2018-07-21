#include "exoutofrange.h"
#include <string.h>
#include <string>

exOutOfRange::exOutOfRange(const char *str_,const char *fileName, int lineNumber):myException(str,lineNumber)
{
//    strcpy(str,"Argument out of range");
   // getMessage();

    strcat(str, fileName);
    strcat(str, ": ");
    strcat(str, str_);
    strcat(str, ". Line: ");

    strcat(str, (std::to_string(lineNumber)).c_str());


}
