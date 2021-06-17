#ifndef LIST_H_
#define LIST_H_
#include <iostream> //size_t
template<class T>
class List
{
    public:
    
    List(); // constructor
    List(const List<T>& a_list); // copy constructor
    ~List(); // destructor
    Node *next;

private:
    Node<T>* head; //pointer to first node
    Node<T>* tail; //pointer to last node
    //nodes 3 pieces information data, next and previous neighbor
    //list also gives information ->link by the node -header,tail and the size
    //int size;
}; // end List
#include "reiverse_linked_list.cpp"
#endif // LIST_H_