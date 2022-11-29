#ifndef __NODE_CPP__
#define __NODE_CPP__
template <class T>
class Node
{
private:
    T data;
    Node<T> *pNext;

public:
    Node();
    ~Node();
    Node(const T);
    
    T getData();
    Node<T> *getpNext();

    void setData(const T &);
    void setpNext(Node<T> *);
};

#endif