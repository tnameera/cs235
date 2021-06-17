#include "List.hpp"

template<class T> 
List<T>::List()
{
    head = tail = nullptr;
    size = 0;
}

template<class T>
List<T>::List(const List<T>& a_list)
{
    //make a copy and link every item
    //have redundant copy of the original list
    //get head of the original list a_list
    Node<T>* curr = a_list.head; //point to the head of a_list

    head = tail = nullptr;
    size = 0;
    while (curr != nullptr)
    {
        //create a newNode with the same data as curr.
        //courtsey Connor Courtien
        insert(size, curr->getItem());
        //in insert method, 
        //we will create a new node with data curr->getItem(),
        //and insert that node to the corresponding position.
       
        curr = curr->getNext();
    }
}

template<class T>
List<T>::~List()
{
    clear();
}

template<class T>
bool List<T>::isEmpty() const
{
    return size == 0;
    //courtesy Michael A Lyashenko and Connor J Courtien
    //or return head == nullptr;
    //or return tail == nullptr;
}

template<class T>
size_t List<T>::getLength() const
{
    //courtesy Zachary M Motassim and Michael A Lyashenko 
    return size;
}

//retains list order, position is 0 to n-1, 
//if position > n-1,
//it inserts at end
template<class T>
bool List<T>::insert(size_t position, const T& new_element)
{
    //make new node with the same value(new element) whose head = head and tail as follows
    Node<T>* newNode = new Node<T>(new_element);
    if (newNode == nullptr) //no allocation of memory to newNode
       return false;

    //courtsey Michael A Lyashenko
    //64-question: how can I insert this newNode to the
    //(position) index of my current list, which has head, tail
    //and size information.
    //Node<T>* prev = nullptr;
    //Node<T>* curr = head;
    //Node<T>* next = curr->getNext(); //TODO: may have problem,
    //curr can be nullptr, so curr->getNext() has exception.
    //int num = 0;
    //while(num < position && curr != nullptr)
    //{ 
    //    //TODO 
    //   prev = curr;
    //    curr = curr->getNext(); //same as (*curr).getNext()    
    //    //next = curr->getNext(); //TODO: may have problem,
    //       //curr might become nullptr after
    //       //curr = curr->getNext();
    //       //Also, we plan to insert right before position,
    //       //so that we need prev info before curr.
    //    num++; 
    //}   

    //Node,T>* curr = getPointer(position);  
    //if (curr == nullptr)
    //but we might lose infor of node of prev node

    //insert newNode before curr
    //TODO: have we considered the effect of inserting
    //a node affecting the current head and/or tail.
    //curr->setNext(newNode);     
    //next->setPrev(newNode);     
    //newNode->setNext(next);     
    //newNode->setPrev(curr);   

    //TODO: insert newNode after prev and before curr.
    newNode->setPrev(prev);
        //prev (aka left) neighbor of newNode is prev
    newNode->setNext(curr);
        //next (aka right) neighbor of newNode is curr

    if (prev != nullptr && curr != nullptr)
    {
        curr->setPrev(newNode); 
            //prev (aka left) neighbor of curr is newNode
            //
            //What if curr is nullptr?
            //curr is nullptr when we insert to the end of list.
            //for example, if we have no node (in the beginning)
            //in the list, we insert newNode,
            //in this case, prev and curr are both nullptr.
            //Or, if we have 1 node, we want to insert newNode
            //at position 1, then prev is the original head 
            //in the current list, and curr is nullptr. 
        prev->setNext(newNode);  //what if prev is nullptr?
            //next (right) neighbor of prev becomes newNode
            //Similar analysis for possibility that prev can be
            //nullptr.
    }
    else if (prev == nullptr && curr == nullptr)
         {
            //in what scenario will prev == nullptr and
            //curr == nullptr?
            head = tail = newNode; 
         }
         else if (prev == nullptr) {
                 //same as (prev == nullptr && curr != nullptr)
                 //courtesy Connor
                 curr->setPrev(newNode);
                 //What happens to head?
                 head = newNode;
              }
              else //prev != nullptr && next == nullptr
              {
                  //courtesy Connor and Syeda
                  prev ->setNext(newNode);
                  tail = newNode;
              }

    size++; //only do it once.
    return true;
}

template<class T>
bool List<T>::remove(size_t position)
{
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    int num = 0;
    while( num < position && curr != nullptr)
    {
        prev =curr;
        curr = curr->getNnext();
        num++
    }

}

template<class T>
T List<T>::getItem(size_t position) const
{
    //redundant, copy from insert method
    //to locate the pointer to the position th element,
    //where position >= 0 && position < size,
    //position is like index
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    int num = 0;
    while(num < position && curr != nullptr)
    { 
        prev = curr;
        curr = curr->getNext(); //same as (*curr).getNext()    
        num++; 
    }   

    //what if curr == nullptr?
    if (curr != nullptr)
       return curr->getItem();
    //what else?
}


//given the index of linked list
//return the pointer to its (index)th element
//if index is not valid (index < 0 || index >= size) we will return nullptr
//put this method as a private method of linked list
// but it will not be used by the users of List<T>CLASS
template<class T>
Node<T>* List<T>::getPointer(int index) const
//node<t> represents we have to work with pointer node type
//List<t> represents the method
//const because dont change the data member just want the value
{ 
    if (index < 0 || index >= size)
    { 
        return nullptr; 
    } 

    //it si fine ut not needed prev
    //since prev will not be returned
    //Node<T>* prev = nullptr; 
    Node<T>* curr = head; 
    int num = 0; 

    //its is ok ,since we filter out index is out OverflowError
    //range f [0,sisew-1], which area valid Inddex
    //in the linled list with Sized//so if curr is nullptr
    //we will not enter the loop while(num < index)
    //so curr = surr->getNext();
    //we will not enter the loop while(num<index)
    //curr is nullptr
    while (num < index)
        { 
        //prev = curr; 
        curr = curr->getNext(); 
        num++ 
        } 
    return curr; }

template<class T>
T List<T>::reverse(size_t position) const
{
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    while (curr != nullptr)
    {
        curr = setNext->prev;//Now change next of current
        prev = curr;// Move prev and curr one step forward 
        curr = next;
        next = next->getNext();//store next node
    }
   return prev
}

template<class T>
void List<T>::clear()
{

}
