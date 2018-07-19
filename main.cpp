#include <iostream>
#include "mylist.h"

//using namespace std;

int main()
{

    myList<int> l;
    l.hello();
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);

    int a = 4;
    l.pushBack(a);

    l.pushFront(5);
    int b = 6;
    l.pushFront(b);

//    myException ex;
//    std::cout << l[4] << std::endl;
    try {
        l[1000];
    }
    catch(myException ex) {
        std::cout<<"myException!\n"<<ex.getMessage();
    }
    catch (int x) {
        std::cout<<"Int Exception:"<<x;
    }

    catch(...) {
        std::cout<<"Other Exception!";
    }
  //  std::cout << l.getSize() << std::endl;
    return 0;
}
