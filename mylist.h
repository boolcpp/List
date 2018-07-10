#ifndef MYLIST_H
#define MYLIST_H
//#include <exception>
typedef unsigned long int size_t;


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
    size_t nodeCount;  //все равно их не может быть меньше 0, экономия 2 bytes


public:
    myList();
    ~myList();
    void hello();
    void pushBack(T &&data);
    void pushBack(T &data);
    size_t getSize(){ return nodeCount;}
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
void myList<T>::pushBack(T &&data)
{
    if(nodeCount == 0)
    {
        headNode = new node<T>(data, nullptr);
    }
    else
    {
        node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        node<T>* endNode = new node<T>(data, nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}
//pushBack for lvalue
template<typename T>
void myList<T>::pushBack(T &data)
{
    if(nodeCount == 0)
    {
        headNode = new node<T>(data, nullptr);
    }
    else
    {
        node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        node<T>* endNode = new node<T>(data, nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}

template<typename T>
T &myList<T>::operator[](int index)
{
    //обработать поведение функции при index > nodeCount
    if (index>nodeCount)
        throw outOfRangeException();
  //unsigned short counter = 0;
  node<T>* currentNode = this->headNode;
  //while (currentNode != nullptr && index>0)
  while (index>0)
  {
      currentNode = currentNode->ptrNextNode;
      index--;
  }
  //if (currentNode==nullptr)
  //    throw 0;
  return currentNode->data;
}

#endif // MYLIST_H
