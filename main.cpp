#include <iostream>
#include "mylist.h"

//using namespace std;

int main()
{

    myList<int> l;
   // l.hello();
    for(size_t i = 0; i < 100; i++)
    {
        l.pushBack(int(i));
    }
    for(size_t k = 100; k > 50; k--)
    {
        l.popFront();
    }

//    myException ex;
//    std::cout << l[4] << std::endl;
//    try
//    {
//        l[1000];
//    }
//    catch(exOutOfRange ex)
//    {
//        std::cout << "exOutOfRange!\n"
//                  << ex.getMessage() << std::endl
//                  << ex.getStrNum() << std::endl;
//        return -1;
//    }
//    catch(myException ex)
//    {
//        std::cout << "myException!\n"
//                  << ex.getMessage() << std::endl
//                  << ex.getStrNum() << std::endl;
//        return -1;
//    }
//    catch (int x)
//    {
//        std::cout << "Int Exception:" << x;
//        return -1;
//    }

//    catch(...)
//    {
//        std::cout << "Other Exception!";
//        return -1;
//    }
  //  std::cout << l.getSize() << std::endl;
    return 0;
}
