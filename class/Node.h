#ifndef __NODE_CPP__
#define __NODE_CPP__
template <class T>
class Node
{
private:
    T data;
    Node<T> *pNext;
    Node<T> *pBack;

public:
    Node();
    ~Node();
    Node(const T&);
    
    T getData();
    Node<T> *getpNext();
    Node<T> *getpBack();
    void setData(const T &);
    void setpNext(Node<T> *);
    void setpBack(Node<T> *);
};

#endif