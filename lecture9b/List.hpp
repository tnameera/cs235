#ifndef LIST_H_
#define LIST_H_
#include <iostream> //size_t
#include "Node.hpp"
template<class T>
class List
{
public:
    List(); // constructor
    List(const List<T>& a_list); // copy constructor
    ~List(); // destructor
    bool isEmpty() const;
    size_t getLength() const;
    bool insert(size_t position, const T& new_element);
      //retains list order, position is 0 to n-1,
      //if position > n-1,
      //it inserts at end
    bool remove(size_t position);//retains list order
    T getItem(size_t position) const;
    void clear();
    void reverse(); //reverse the original linked list
    List<T> get_reverse_list() const;
        //do not change the original linked list,
        //but return a reversed version of it.

private:
    Node<T>* head; //pointer to first node
    Node<T>* tail; //pointer to last node
    int size;

    Node<T>* getPointer(int index) const;

}; // end List
#include "List.cpp"
#endif // LIST_H_
