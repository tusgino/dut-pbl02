#ifndef __LIST__
#define __LIST__

#include "..\..\..\class\List.h"

template <class T>
List<T>::List()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
    this->size = 0;
}

template <class T>
List<T>::~List()
{
    Node<T> *pTemp = this->pHead;
    while(pTemp){
        pTemp->~Node();
        pTemp = pTemp->getpNext();
    }
}

template <class T>
void List<T>::push_back(const T &data)
{
    Node<T> *pTemp = this->pHead; 
    Node<T> *pAdd = new Node<T>(data); // Cấp phát bộ nhớ cho Node cần thêm

    if (pTemp == nullptr) // DS rỗng 
    {
        this->pHead = pAdd; // pAdd là pHead
        this->pTail = pAdd; // pAdd là pTail
        this->size++;
    }
    else
    {
        this->pTail->setpNext(pAdd); // Liên kết pNext của Node pTail hiện tại cho Node mới
        pAdd->setpBack(this->pTail); // Liên kết pBack của Node mới cho Node pTail hiện tại
        this->pTail = pAdd; // Cho con trỏ pTail trỏ tới pAdd;
        this->size++;
    }
}

template <class T>
Node<T> *List<T>::getpHead()
{
    return this->pHead;
}

template <class T>
Node<T> *List<T>::getpTail()
{
    return this->pTail;
}

template <class T>
int List<T>::getSize()
{
    return this->size;
}

template <class T>
void List<T>::deleteNode(const int &index)
{
    if (index < 0 || index >= this->size) // index nằm ngoài vùng xóa
        return;
    if (index == 0)
    {
        this->pHead = this->pHead->getpNext(); // Cho con trỏ pHead trỏ tới liên kết tiếp theo 
        this->pHead->setpBack(nullptr); // Set cho pBack của pHead trỏ tới NULL
        this->size--;
    }
    else if (index + 1 == this->size)
    {
        this->pTail = this->pTail->getpBack(); // Cho con trỏ pTail trỏ tới liên kết sau
        this->pTail->setpNext(nullptr);        // Set cho pNext của pHead trỏ tới NULL
        this->size--;
    }
    else
    {
        Node<T> *pBefore = this->pHead, *pAfter = nullptr; 
        for (int i = 0; i < index; i++)
        {
            pAfter = pBefore;
            pBefore = pBefore->getpNext();
        }
        // Bước này thì ta có pBefore trỏ tới Node cần xóa, pAfter trỏ tới Node ngay trước Node cần xóa

        pAfter->setpNext(pBefore->getpNext()); // Cho pAfter liên kết tới Node mà pBefore đang liên kết
        pBefore = pBefore->getpNext(); // Cho pBefore trỏ tới Node tiếp theo 
        pBefore->setpBack(pAfter); // Set lại pBack của Node mà con trỏ pBefore để liên kết tới pAfter
        this->size--;
        // pBefore->~Node();
    }
}

template <class T>
Node<T> &List<T>::operator[](const int &index)
{
    Node<T> *pTemp = this->pHead;

    for (int i = 0; i < index; i++)
    {
        pTemp = pTemp->getpNext();
    }

    return pTemp;
}

#endif