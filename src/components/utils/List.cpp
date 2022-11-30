#ifndef __LIST__
#define __LIST__

#include "..\..\..\class\List.h"

template <class T>
List<T>::List()
{
    this->pHead = nullptr;
    this->size = 0;
}

template <class T>
List<T>::~List()
{
}

template <class T>
void List<T>::push_back(const T &data)
{
    Node<T> *pTemp = this->pHead;
    Node<T> *pAdd = new Node<T>(data);

    if (pTemp == nullptr)
    {
        this->pHead = pAdd;
        this->size++;
    }
    else
    {
        while (pTemp->getpNext() != nullptr)
        {
            pTemp = pTemp->getpNext();
        }

        pTemp->setpNext(pAdd);
        this->size++;
    }
}

template <class T>
Node<T> *List<T>::getpHead()
{
    return this->pHead;
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

template <class T>
void List<T>::deleteNode(const int &index)
{

    if (index == 0)
    {
        this->pHead = this->pHead->getpNext();
        size--;
    }
    else
    {
        Node<T> *pBefore = this->pHead, *pAfter = nullptr;
        for (int i = 0; i < index; i++)
        {
            pAfter = pBefore;
            pBefore = pBefore->getpNext();
        }

        pAfter->setpNext(pBefore->getpNext());
        size--;
        pBefore->~Node();
    }
}

#endif