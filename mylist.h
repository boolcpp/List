#ifndef MYLIST_H
#define MYLIST_H
#include "myexception.h"
//#include <stddef.h>  //for size_t, т.к. MinGW ругается на:
                     //typedef unsigned long int size_t;
                     //жертва кроссплатформенности
typedef unsigned long int sizeT;

//catching errors
class outOfRangeException {
};

//класс, экземпляром которого будет элемент из списка
template <typename T>
class node
{
public:
    node* ptrNextNode; // указатель на следующий элемент
    T data;      // данные внутри элемента списка

    node(T data = T(), node* ptrNextNode = nullptr) //при создании нового элемента списка нач условия
    {
        this->data = data;
        this->ptrNextNode = ptrNextNode;
    }
    ~node();    //деструктор для элемента списка подумать

};

// класс, экземпляром которого будет односвязный список
template <typename T>
class myList
{
private:
    node<T>* headNode;
    sizeT nodeCount;  //все равно их не может быть меньше 0, экономия 2 bytes


public:
    myList();
    ~myList();
    void hello();
    void pushBack(T &&rData);
    void pushBack(T &lData);
    void pushFront(T &&rData);
    void pushFront(T &lData);
    sizeT getSize(){ return nodeCount;}
    T& operator[](int index);
};

template<typename T>
myList<T>::myList()
{
    headNode = nullptr;
    nodeCount = 0;

}

template<typename T>
myList<T>::~myList()
{

}

template<typename T>
void myList<T>::hello()
{
    std::cout << "Hello from myList" << std::endl;
}
//pushBack for rvalue
template<typename T>
void myList<T>::pushBack(T &&rData)
{
    if(nodeCount == 0)
    {
        headNode = new node<T>(rData, nullptr);
    }
    else
    {
        node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        node<T>* endNode = new node<T>(rData, nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}
//pushBack for lvalue
template<typename T>
void myList<T>::pushBack(T &lData)
{
    if(nodeCount == 0)
    {
        headNode = new node<T>(lData, nullptr);
    }
    else
    {
        node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        node<T>* endNode = new node<T>(lData, nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}

template<typename T>
void myList<T>::pushFront(T &&rData)
{
    node<T> *newHeadNode = new node<T>(rData, this->headNode);

  //  newHeadNode->ptrNextNode = this->headNode;

    headNode = newHeadNode;
    nodeCount++;
}

template<typename T>
void myList<T>::pushFront(T &lData)
{
    node<T> *newHeadNode = new node<T>(lData, this->headNode);

  //  newHeadNode->ptrNextNode = this->headNode;

    headNode = newHeadNode;
    nodeCount++;
}


template<typename T>
T &myList<T>::operator[](int index)
{
    //обработать поведение функции при index > nodeCount
  if (index>nodeCount)
    throw myException();

  node<T>* currentNode = this->headNode;

  while (index>0)
  {
      currentNode = currentNode->ptrNextNode;
      index--;
  }

  return currentNode->data;
}

#endif // MYLIST_H
