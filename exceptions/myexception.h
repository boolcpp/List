#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class myException
{
protected:
    char str[128];
    int strNumber;
public:
  myException();
  myException(const char* str, int strNumber_=0);

  const char* getMessage();
  int getStrNum();

};

#endif // MYEXCEPTION_H
