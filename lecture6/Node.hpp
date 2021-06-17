#ifndef NODE_H_
#define NODE_H_
template<class T>
class Node
{
public:
    Node();
    Node(const T& item);
    Node(const T& item, Node* next);
    T getItem() const;
    Node* getNext() const;
    void setItem(const T& item);
    void setNext(Node* next);

private:
    T item_;
    Node* next_;
};
#include "Node.cpp"
#endif
