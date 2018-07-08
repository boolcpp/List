#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

template <typename T>
class myList
{
public:
    myList();
    void hello();
};

template<typename T>
myList<T>::myList()
{

}

template<typename T>
void myList<T>::hello()
{
    std::cout << "Hello from myList" << std::endl;
}



#endif // MYLIST_H
