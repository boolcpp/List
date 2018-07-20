#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class myException
{
protected:
    char str[128];
    int strnum;
public:
  myException();
  myException(const char* str, int strnum_=0);

  const char* getMessage();
  int getStrnum();

};

#endif // MYEXCEPTION_H
