#ifndef LIST_H_
#define LIST_H_
#include <iostream> //size_t
#include "Node.hpp"
template<class T>
class List
{
public:
    List(); // constructor
    List(const List<T>& a_list); // copy constructor //deep copy
    //a.head = head
    ~List(); // destructor
    bool isEmpty() const;
    size_t getLength() const;
    //WHAT IS size_t??
    bool insert(size_t position, const T& new_element);
      //if there are 5 elements posiiton can be 6. 0-first, 1-second.....5th-sixth 
      //retains list order, position is 0 to n-1,
      //if position > n-1,
      //it inserts at end
    bool remove(size_t position);//retains list order()
    //if you give the index we will remove that element
    //both remove and insert will change the list

    bool reverse(size_t position);

    T getItem(size_t position) const;
    //WHAT IS T???
    //we will get the item 
    //but it will not change the list
    void clear();

private:
    Node<T>* head; //pointer to first node
    Node<T>* tail; //pointer to last node
    //nodes 3 pieces information data, next and previous neighbor
    //list also gives information ->link by the node -header,tail and the size
    int size;
    Node<T>* getPointer(int index) const;
    //giving integer we will get item pointer
}; // end List
#include "List.cpp"
#endif // LIST_H_
