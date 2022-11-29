template <class T>
class Node
{
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