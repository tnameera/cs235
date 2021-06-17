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

//courtesy Conner Courtien
template<class T>
bool List<T>::remove(size_t position)
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

/*
//another version of remove a node from a double linked list
template<class T>
bool List<T>::remove(size_t position)
{
    Node<T>* prev = nullptr;
    Node<T>* curr = head;

    int num = 0;
    while (num < position)
    {
        prev = curr;
        curr = curr->getNext();
        num++;
    }

    if (curr == nullptr) //nothing to delete
       return false;

    //curr != nullptr
    if (prev != nullptr)
    {
       prev->setNext(curr->getNext());
       if (curr->getNext() != nullptr)
          curr->getNext()->setPrev(prev);
    }
    else //prev == nullptr, delete head
         {
            head = curr->getNext();
            if (head == nullptr)
               tail = head;
            else head->setPrev(nullptr);
         }

    size--;
    return true;
}
*/

template<class T>
T List<T>::getItem(size_t position) const
{
    //redundant, copy from insert method
    //to locate the pointer to the position th element,
    //where position >= 0 && position < size,
    //position is like index
//    Node<T>* prev = nullptr;
//    Node<T>* curr = head;
//    int num = 0;
//    while(num < position && curr != nullptr)
//    { 
//        prev = curr;
//        curr = curr->getNext(); //same as (*curr).getNext()    
//        num++; 
//    }   

    Node<T>* curr = getPointer(position);

    //what if curr == nullptr?
    if (curr != nullptr)
       return curr->getItem();
    else throw new std::out_of_range(
             "\n" + std::to_string(position) 
             + " is out of range.\n");
}

template<class T>
void List<T>::clear()
{
    //courtesy Conner and Janna
    while (head != nullptr)
        remove(0);
}

//courtesy Michael A Lyashenko
//Given the index of a linked list,
//return the pointer to its (index)th element.
//If index is not valid (index < 0 || index >= size),
//return nullptr.
//Put this method as a private method in List.hpp,
//since this method will be used by
//insert, remove, and getItem methods of linked list,
//but it will not be used by the users of List<T> class.
template<class T>
Node<T>* List<T>::getPointer(int index) const
{ 
    if (index < 0 || index >= size)
       return nullptr; 

    //Node<T>* prev = nullptr;  //it is fine, but not needed,
    //since prev is not going to be returned.
    Node<T>* curr = head; 

    int num = 0; 

    //It is ok, since we filter out index is out of 
    //the range of [0, size-1], which are valid index
    //in the linked list with size.
    //So if curr is nullptr,
    //we will not enter the loop while (num < index),
    //so curr = curr->getNext();
    //will not have a chance to run IF
    //curr is nullptr.
    while (num < index)
    {  
        //prev = curr; //not needed
        curr = curr->getNext(); 
        num++;
    } 

    return curr; 
}

//courtesy Michael, this version changes 
//the original linked list directly.
template<class T>
void List<T>::reverse()
{
    for (int i = 0; i < size; i++)
    {   
        Node<T>* n = tail; 
        //whenever you use n->...,
        //you need to check whether n is nullptr or not
        //verification: if we can enter the loop,
        //size is not 0,
        //so n cannot be nullptr. 
        insert(i, n->getItem()); 
        remove(size-1); 
    }

    //In the very beginning,
    //Suppose we have a linked list
    //6->1->3->2
    //size is 4
    //i = 0
    //    i < size? yes
    //    n = pointer to last element 2
    //    insert(0, n->getItem());
    //        would result in 2->6->1->3->2
    //    now size is 5 (because we insert a node)
    //    remove(size-1)//remove the element indexed at 4
    //        would result in 2->6->1->3 and size is 4

    //i = 1
    //    i < size? yes
    //    n = pointer to the current tail, which is 3
    //    insert(1, n->getItem())
    //        would result in 2->3->6->1->3 and size 5
    //    remove(size-1)
    //        would result in 2->3->6->1 and size 4
}

//courtesy Connor
template<class T>
List<T> List<T>::get_reverse_list() const
{
    Node<T>* curr = tail;
    List<T> b_list;

    int index = 0;
    while (curr != nullptr)
    {
	 //b_list.insert(b_list.getLength(), curr->getItem());
              //work, without needing to use variable index.
              //However, b_list.getLength() does involve
              //method calling overhead.
	 b_list.insert(index, curr->getItem());
	 curr = curr->getPrev();
         index++;
    }

    //Suppose the current linked list is 6->1->3->2.
    //index is 0
    //b_list is an empty list.
    //curr is pointing to the tail, which is 2.
    //curr != nullptr? Yes
    //   b_list.insert(0, 2);
    //      2
    //   curr = curr->getPrev();
    //      curr is pointing to element 3
    //   index++; //index is 1
    //curr != nullptr? Yes
    //   b_list.insert(1, 3)
    //      2->3
    //   curr = curr->getPrev();
    //      curr is pointing to element 1
    //   index++; //index is 2
    return b_list;
}
