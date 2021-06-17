#include "Node.hpp"
#include <iostream> //nullptr
template<class T>
Node<T>::Node()//default constructor
{
    //item_ = null; //?
    next_ = nullptr;
}

template<class T>
Node<T>::Node(const T& item)
{
    item_ = item;
    next_ = nullptr;//if next not specified then by default next is nullptr
}

template<class T>
Node<T>::Node(const T& item, Node* next)
{
    item_ = item;
    next_ = next;
}

template<class T>
T Node<T>::getItem() const
{
   return item_;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next_;
}

template<class T>
void Node<T>::setItem(const T& item)
{
    item_ = item;
}

template<class T>
void Node<T>::setNext(Node* next)
{
    next_ = next;
}
