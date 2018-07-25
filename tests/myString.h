#ifndef MYSTRING_H
#define MYSTRING_H


class myString
{
private:
    char* buf;
    int len;
public:
    myString();
    myString(const char* src);
    myString(myString& src);
    myString(myString&& src);
    ~myString();
    //myString& myString(const myString&src);
    //myString& myString(myString&&src);
};

#endif // MYSTRING_H
