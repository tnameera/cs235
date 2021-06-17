//from typing import Sized
//given the index of linked list
//return the pointter to its (index < 0 || index > =size)
//since this methid will be used by 
//insert, remove and getItem methods of linked list,
//but it will not be used by users of list class
//


Node<T>* List<T>::getPointer(int index) const
{ 
    if (index < 0 || index >= size)
    { 
        return nullptr;
    } 

    //Node<T>* prev = nullptr; 
    Node<T>* curr = head; 
    int num = 0; 
    curr = surr->getNext();
    
    while (num < index)
        { 
        //prev = curr; 
        curr = curr->getNext(); 
        num++ 
        } 
    return curr; }