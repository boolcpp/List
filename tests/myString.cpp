#include "myString.h"
#include <string.h>
#include <iostream>

myString::myString()
{
    std::cout<<"myString() called";
    buf = nullptr;
    len = 0;
}

myString::myString(const char* src)
{
    std::cout<<"myString(const char* src) called"<<std::endl;
    len = strlen(src);
    buf = new char[len + 1];
    strcpy(buf,src);
}

myString::myString(myString& src)
{
    std::cout<<"myString(myString& src) called"<<std::endl;
    if (src.buf == nullptr) {
        buf = nullptr;
        len = 0;
        return;
    }

    len = src.len;
    buf = new char[len + 1];
    strcpy(buf, src.buf);
}

myString::myString(myString&& src)
{
    std::cout<<"myString(myString&& src) called"<<std::endl;
    len = src.len;
    buf = src.buf;
    src.buf = nullptr;
    src.len = 0;
}

myString& myString::operator = (const myString& src)
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

myString& myString::operator = (myString&& src)
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
    std::cout<<"~myString called"<<std::endl;
    if(buf != nullptr)
    {
        delete [] buf;
    }
}

const char* myString::getString() {
    if (buf==nullptr)
        return "";
    return buf;
}
