#ifndef __List_CPP__
#define __List_CPP__

#include "Node.h"
template <class T>
class List
{
private:
    Node<T> *pHead;
    Node<T> *pTail;
    int size;

public:
    List();
    ~List();
    Node<T> *getpHead();
    Node<T> *getpTail();
    int getSize();

    void push_back(const T &);
    void deleteNode(const int &);
    Node<T>& operator[](const int&);
};
#endif