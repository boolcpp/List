#include <iostream>
#include "mylist.h"

//using namespace std;

int main()
{

    myList<int> l;
   // l.hello();
    l.pushBack(3);
    int a = 13;
    l.pushBack(a);

    a = 22;
    myException ex;
   // std::cout << l[4] << std::endl;
    try
    {
        l[1000];
    }
    catch(exOutOfRange ex)
    {
        std::cout << "exOutOfRange!\n" << std::endl
                    << ex.getMessage() << std::endl;
//                  << ex.getStrNum() << std::endl;
        return -1;
    }
    catch(myException ex)
    {
        std::cout << "myException!\n"
                  << ex.getMessage() << std::endl
                  << ex.getStrNum() << std::endl;
        return -1;
    }
    catch (int x)
    {
        std::cout << "Int Exception:" << x;
        return -1;
    }

    catch(...)
    {
        std::cout << "Other Exception!";
        return -1;
    }
    return 0;
}


  //  std::cout << l.getSize() << std::endl;
