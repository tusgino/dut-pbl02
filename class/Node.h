#ifndef __NODE_CPP__
#define __NODE_CPP__
template <class T>
class Node
{
private:
    T data;
    Node<T> *pNext;
    // Node<T> *pPrev;

public:
    Node();
    ~Node();
    Node(const T);
    
    T getData();
    Node<T> *getpNext();
    // Node<T> *getpPrev();

    void setData(const T &);
    void setpNext(Node<T> *);
    // operator =(const Node<T> *);
    
    // void setpPrev(Node<T> *);
};

#endif