#include "Node.hpp"
#include <iostream> //nullptr
template<class T>
Node<T>::Node()
{
    //item_ = null; //Not work, do not know item_ value
    next_ = nullptr;
    prev_ = nullptr; //ADD
}

template<class T>
Node<T>::Node(const T& item)
{
    item_ = item;
    next_ = nullptr;
    prev_ = nullptr; //ADD
}

template<class T>
Node<T>::Node(const T& item, Node* next)
{
    item_ = item;
    next_ = next;
    prev_ = nullptr;
}

template<class T>
Node<T>::Node(const T& item, Node* next, Node* prev)
{
    item_ = item;
    next_ = next;
    prev_ = prev;
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
Node<T>* Node<T>::getPrev() const
{
    return prev_;
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

template<class T>
void Node<T>::setPrev(Node* prev)
{
    prev_ = prev;
}
