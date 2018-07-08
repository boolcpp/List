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
    return 0;
}
