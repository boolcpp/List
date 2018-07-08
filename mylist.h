#ifndef MYLIST_H
#define MYLIST_H

//класс, экземпляром которого будет элемент из списка
template <typename T>
class Node
{
public:
    Node* ptrNextNode; // указатель на следующий элемент
    T data;      // данные внутри элемента списка

    Node(T data = T(), Node* ptrNextNode = nullptr) //при создании нового элемента списка нач условия
    {
        this->data = data;
        this->ptrNextNode = ptrNextNode;
    }
    ~Node();    //деструктор для элемента списка подумать

};

template <typename T>
class myList
{
private:
    Node<T>* headNode;
    unsigned short int nodeCount;  //все равно их не может быть меньше 0, экономия 2 bytes


public:
    myList();
    ~myList();
    void hello();
    void pushBack(T data);
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

template<typename T>
void myList<T>::pushBack(T data)
{
    if(nodeCount == 0)
    {
        headNode = new Node<T>(data, nullptr);
    }
    else
    {
        Node<T>* currentNode = this->headNode;
        while(currentNode->ptrNextNode != nullptr)
        {
            currentNode = currentNode->ptrNextNode;
        }
        Node<T>* endNode = new Node<T>(data, nullptr);
        currentNode->ptrNextNode = endNode;
    }
    nodeCount++;
}



#endif // MYLIST_H
