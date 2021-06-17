#ifndef ADT_H_
#define ADT_H_
#include <iostream> //size_t
#include "Node.hpp"
template<class T>
class Adt
{
public:
    Adt(); // constructor
    void push(const T& new_element);
    void pop();
    bool insert(size_t position, const T& new_element);
    bool remove(size_t position);//retains list order
    void clear();

private:
    Node<T>* head; //pointer to first node
    Node<T>* tail; //pointer to last node
    int size;

}; // end List
#include "List.cpp"
#endif // LIST_H_