#include <iostream>
#include "mylist.h"
#include "tests/myString.h"
//using namespace std;

int main()
{

    myList<myString> l;

//    char chMas[] = "asdasdasd";

//    myString str1(myString &chMas);
   // std::cout << l[4] << std::endl;

    myString t("123");
    myString t2 = t;
    t = "qwer";
    myString t3 = t;
    t = "qqq";
    //l.pushBack(myString("test"));
    l.pushBack(t);
    l.pushBack(t2);
    l.pushBack(std::move(t3));

//    myList<int> l1;
//    l1.pushBack(0);
//    l1.pushBack(1);
//    l1.pushBack(2);
//    l1.pushBack(3);

    auto it = l.begin();
    while (!it.isNull())
    {
        std::cout<<it.getData().getString()<<std::endl;
        ++it;
    }
//    try
//    {
//        l[1000];
//    }
//    catch(exOutOfRange ex)
//    {
//        std::cout << "exOutOfRange!\n" << std::endl
//                    << ex.getMessage() << std::endl;
////                  << ex.getStrNum() << std::endl;
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
    return 0;
}


  //  std::cout << l.getSize() << std::endl;
