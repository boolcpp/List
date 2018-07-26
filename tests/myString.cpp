#include "myString.h"
#include <string.h>
#include <iostream>

myString::myString()
{
    buf = nullptr;
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
    if (src.buf == nullptr) {
        buf = nullptr;
        len = 0;
        return;
    }

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
    src.len = 0;
    std::cout<<"myString(myString&&) called"<<std::endl;
}

myString& myString::operator=(const myString& src)
{
    std::cout << "operator = called for &" << std::endl;
    this->len = src.len;
    if(this->buf != nullptr)
    {
        delete [] buf;
    }
    if (src.buf == nullptr) {
        buf = nullptr;
        len = 0;
        return *this;
    }
    this->buf = new char[this->len + 1];
    strcpy(buf, src.buf);

    return * this;
}

myString& myString::operator =(myString&& src)
{
    std::cout << "operator = called for &&" << std::endl;

    this->len = src.len;
    if(this->buf != nullptr)
    {
        delete[] buf;
    }
    if (src.buf == nullptr) {
        buf = nullptr;
        len = 0;
        return *this;
    }
    this->buf = src.buf;
    src.buf = nullptr;
    src.len = 0;

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

const char* myString::getString() {
    if (buf==nullptr)
        return "";
    return buf;
}
