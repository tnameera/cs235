#include "Adt.hpp"

template<class T> 
Adt<T>::Adt()
{
    head = tail = nullptr;
    size = 0;
}

template<class T>
bool Adt<T>::insert(size_t position, const T& new_element)
{
    Node<T>* newNode = new Node<T>(new_element);
    if (newNode == nullptr) //no allocation of memory to newNode
       return false;

    //courtsey Michael A Lyashenko
    //64-question: how can I insert this newNode to the
    //(position) index of my current list, which has head, tail
    //and size information.
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    //Node<T>* next = curr->getNext(); //TODO: may have problem,
    //curr can be nullptr, so curr->getNext() has exception.
    int num = 0;
    while(num < position && curr != nullptr)
    { 
        //TODO 
        prev = curr;
        curr = curr->getNext(); //same as (*curr).getNext()    
        //next = curr->getNext(); //TODO: may have problem,
           //curr might become nullptr after
           //curr = curr->getNext();
           //Also, we plan to insert right before position,
           //so that we need prev info before curr.
        num++; 
    }     


    //Node<T>* curr = getPointer(position);
    //if (curr == nullptr) //no such location,
    //but we might lose the info of node to prev node. 

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
bool Adt<T>::remove(size_t position)
{
//    Node<T>* prev = nullptr;
//    Node<T>* curr = head;
//
//    int num = 0;
//    while (num < position && curr != nullptr)
//    {
//        prev = curr;
//        curr = curr->getNext();
//        num++;
//    }

    Node<T>* curr = getPointer(position);

    //now curr is the node to be removed.
    if (curr == nullptr) //there is no node to be deleted
       return false;

    //curr != nullptr
    Node<T>* prev = curr->getPrev();
    Node<T>* next = curr->getNext(); //next node following curr

    //(1) In insert method,
    //insert a node between prev and curr,
    //update head and tail depending on prev and curr.
    //(2) In remove method, 
    //remove curr between prev and next,
    //update head and tail depending on prev and next.
    if (prev != nullptr && next != nullptr) 
       //good, delete in middle
    {
    	prev->setNext(next);
    	next->setPrev(prev);
    }
    else if (prev == nullptr && next != nullptr)
         //curr is the head
    {
    	 next->setPrev(nullptr);
         head = next;
    }
    else if (next == nullptr && prev != nullptr)
         {   //curr is the tail
    	     prev->setNext(nullptr);
    	     tail = prev;
         }
         else //prev and next == nullptr, curr is the only node 
         {
    	     head = nullptr;
    	     tail = nullptr;
         }
   
    //release memory of curr node
    delete curr;
    curr->setNext(nullptr);
    curr->setPrev(nullptr);
    curr = nullptr;
    
    size--;
    
    return true;
}

template<class T>
void Adt<T>::pop()
{
    remove(0);
}


template<class T>
void Adt<T>::push(const T& new_element)
{
    insert(0, new_element);
}