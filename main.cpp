#include <iostream>
#include "mylist.h"

//using namespace std;

int main()
{

    myList<int> l;
    l.hello();
    l.pushBack(5);
    l.pushBack(22);
    l.pushBack(43);
    l.pushBack(167);
    int a = 3;
    l.pushBack(a);

    std::cout << l[4] << std::endl;
    try {
        l[1000];
    }
    catch(outOfRangeException ex) {
        std::cout<<"OutOfRangeException!";
    }
    catch (int x) {
        std::cout<<"Int Exception:"<<x;
    }

    catch(...) {
        std::cout<<"Other Exception!";
    }

    return 0;
}
