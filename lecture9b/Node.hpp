#ifndef NODE_H_
#define NODE_H_
template<class T>
class Node
{
public:
    Node();
    Node(const T& an_item);
    Node(const T& an_item, Node<T>* next_node_ptr);
    Node(const T& an_item, Node<T>* next_node_ptr, 
         Node<T>* prev_node_ptr);
    void setItem(const T& an_item);
    void setNext(Node<T>* next);
    void setPrev(Node<T>* prev);
    T getItem() const;
    Node<T>* getNext() const;
    Node<T>* getPrev() const;

private:
    T item_; // A data item 
    Node<T>* next_; // Pointer to next node
    Node<T>* prev_; // Pointer to previous node 
}; // end Node
#include "Node.cpp"
#endif // NODE_H_
