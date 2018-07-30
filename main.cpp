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
    t = "222";
    myString t3 = t;
    t = "333";
    //l.pushBack(myString("test"));
//    l.pushBack(t);
//    l.pushBack(t2);
//    l.pushBack(std::move(t3));

    l.pushFront(t);
    l.pushFront(t2);
    l.pushFront(std::move(t3));

    //std::cout << l.headNode->data.getString() << std::endl;

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
