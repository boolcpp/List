#include "myString.h"
#include <string.h>
#include <iostream>

myString::myString()
{
    buf = new char [1];
    buf[0] = 0;
    len = 0;
    std::cout<<"myString() called";
}

myString::myString(const char* src)
{
    len = strlen(src);
    buf = new char[len+1];
    strcpy(buf,src);
    std::cout<<"myString(const char*) called"<<std::endl;
}

myString::myString(myString& src)
{
    len = src.len;
    buf = new char[len + 1];
    strcpy(buf, src.buf);
    std::cout<<"myString(myString &) called"<<std::endl;
}

myString::myString(myString&& src)
{
    len = src.len;
    buf = src.buf;
    src.buf = nullptr;
    std::cout<<"myString(myString&&) called"<<std::endl;
}

myString& myString::operator=(const myString& src)
{
    std::cout << "operator = called" << std::endl;
    this->len = src.len;
    if(this->buf != nullptr)
    {
        delete [] buf;
    }
    this->buf = new char[this->len + 1];
    strcpy(buf, src.buf);

    return * this;
}

myString::~myString()
{
    if(buf != nullptr)
    {
        delete [] buf;
    }
    std::cout<<"~myString called"<<std::endl;
}
