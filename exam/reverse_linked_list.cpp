#include "reverse_linked_list.hpp"

template<class T> 
List<T>::List()
{
    curr = head
    prev = nullptr
    next = nullptr
}

    //Iterate through the linked list. In loop, do following. 
    // This is where actual reversing happens 
    while (curr != nullptr)
    {
        next = setNext->prev;//store next node 
        prev = curr;// Move prev and curr one step forward 
        curr = next;
        curr = next->prev;//Now change next of current   
        
    }
   
   
    curr = head
    prev = nullptr
    next = nullptr



