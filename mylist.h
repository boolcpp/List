#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include "myexception.h"
#include "exoutofrange.h"
//#include <stddef.h>  //for size_t, т.к. MinGW ругается на:
                     //typedef unsigned long int size_t;
                     //жертва кроссплатформенности
typedef unsigned long int sizeT;

template <typename T> class myList;
//класс, экземпляром которого будет элемент из списка
template <typename T>
class node
{
public:
    node* ptrNextNode; // указатель на следующий элемент
    T data;      // данные внутри элемента списка

    //конструктор для lvalue
    node(T& data, node* ptrNextNode = nullptr) //при создании нового элемента списка нач условия
    {

        this->data = data;
        this->ptrNextNode = ptrNextNode;
    }

    //конструктор для rvalue
    node(T&& data, node* ptrNextNode = nullptr) //при создании нового элемента списка нач условия
    {
        this->data = std::move(data);
        this->ptrNextNode = ptrNextNode;
    }
    //деструктор для элемента списка подумать
    ~node()
    {
        //что то тут я хотел написать а теперь уже забыл
    }

};

template <typename T>
class listIterator {
    //friend class myList<T>;
public:
    node<T>* current;
    node<T>* prev;
    myList<T> *list;
public:
    listIterator() { }
    T& getData() {
        if (current==nullptr)
            throw myException();
        return current->data;
    }
    void next()
    {
        if (current==nullptr)
            return;
        prev = current;
        current = current->ptrNextNode;
    }
    bool isNull() {
        return current==nullptr;
    }

    listIterator<T> operator++() {
        next();
        return *this;
    }
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

    void pushBack(T&& rData);
    void pushBack(T& lData);

    void pushFront(T&& rData);
    void pushFront(T& lData);
    void popFront();
    void clear();

    sizeT getSize() const { return nodeCount;}
    bool empty() const;

    T& operator[](int index);

    listIterator<T> begin() {
        listIterator<T> it;
        it.current = headNode;
        it.prev = nullptr;
        it.list = this;
        return it;
    }

//    void removeAt(listIterator& it) {
//        if (it.list != this)
//            throw myException();
//        TODO Remove
//    }
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
    clear();
}

template<typename T>
void myList<T>::hello()
{
    std::cout << "Hello from myList" << std::endl;
}
//pushBack for rvalue
template<typename T>
void myList<T>::pushBack(T&& rData)
{
    if(nodeCount == 0)
    {
        headNode = new node<T>(std::move(rData), nullptr);
    }
    else
    {
        node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        node<T>* endNode = new node<T>(std::move(rData), nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}
//pushBack for lvalue
template<typename T>
void myList<T>::pushBack(T& lData)
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
void myList<T>::pushFront(T&& rData)
{
    node<T> *newHeadNode = new node<T>(rData, this->headNode);

  //  newHeadNode->ptrNextNode = this->headNode;

    headNode = newHeadNode;
    nodeCount++;
}
// pushFront for lvalue
template<typename T>
void myList<T>::pushFront(T& lData)
{
    node<T> *newHeadNode = new node<T>(lData, this->headNode);

  //  newHeadNode->ptrNextNode = this->headNode;

    headNode = newHeadNode;
    nodeCount++;
}

template<typename T>
void myList<T>::popFront()
{
    if(headNode != nullptr)
    {
        node<T>* temp = headNode;
        headNode = headNode->ptrNextNode;

        delete temp;
        nodeCount--;
    }
    else
    {
        throw "Can not delete member of empty container";
    }

}

template<typename T>
void myList<T>::clear()
{
    if(headNode == nullptr)
    {
        throw "bad quantity of elements in myList";
    }
    while (headNode != nullptr)
    {
        popFront();
    }
}

template<typename T>
bool myList<T>::empty() const
{
    if (nodeCount == 0) {
        return  true;
    }
    else
    {
        return false;
    }
}


template<typename T>
T& myList<T>::operator[](int index)
{
    //обработать поведение функции при index > nodeCount
  if (index>nodeCount)
    //throw myException("Out of range!");//10.1
    //  throw myException("",__LINE__);//exOutOfRangeeyException("",__LINE__);
      throw exOutOfRange("Element number is out of range",__FILE__, __LINE__);
  node<T>* currentNode = this->headNode;

  while (index>0)
  {
      currentNode = currentNode->ptrNextNode;
      index--;
  }

  return currentNode->data;
}

#endif // MYLIST_H
