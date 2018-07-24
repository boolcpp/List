#ifndef MYSTRING_H
#define MYSTRING_H


class myString
{
private:
    char* buf;
    int len;
public:
    myString();
    myString(myString& src);
    myString(myString&& src);
    ~myString();
};

#endif // MYSTRING_H
