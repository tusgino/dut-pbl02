

#include "..\..\..\Class\Node.h"

template <class T>
Node<T>::Node()
{
}

template <class T>
Node<T>::Node(const T data)
{
    this->data = data;
    this->pNext = nullptr;
}

template <class T>
Node<T>::~Node()
{
}
template <class T>
T Node<T>::getData()
{
    return this->data;
}
template <class T>
Node<T> *Node<T>::getpNext()
{
    return this->pNext;
}

template <class T>
void Node<T>::setData(const T &data)
{
    this->data = data;
}

template <class T>
void Node<T>::setpNext(Node<T> *pNext)
{
    this->pNext = pNext;
}
