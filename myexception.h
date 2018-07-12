#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class myException
{
protected:
    char str[128];
public:
  myException();
  myException(const char* str);

  const char* getMessage();

};

#endif // MYEXCEPTION_H
