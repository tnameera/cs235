#include "List.hpp"

template<class T> 
List<T>::List()
{
    head = nullptr;
    tail = 0;

}

template<clasvector<MyClass*> vecs T>
List<T>::List(const List<T>& a_list)
{
    head = tail = nullptr;
    size = 0;
    //get head of the original list a_list
    note<T>* Curr = a_list.head; // point to the heads of a a_list
    Node<T> newNode;
    while( curr != nullptr)
    {
        //create a newnode with the same data as curr
        //courtesy Connor Courtein
        insert(size, curr->getItem())
        newNode = new Node<T>(curr->getItem());
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
    return size == 0; //same as return head == nullptr;
                      //same as return tail == nullptr;
}

template<class T>
size_t List<T>::getLength() const
{
    return size;
}

//retains list order, position is 0 to n-1, 
//if position > n-1,
//it inserts at end
template<class T>
bool List<T>::insert(size_t position, const T& new_element)
{
    Node<T>* newNode = new Node<T>(new_element;
    Node<T>*curr = head;
    Node<T>*next = curr->getNext();
    int num = 0;
    while(num<position)
        {curr.getNext(); 
        //next = curr->getNext(); same as (*curr).getNext()
        num++
        }   
        //insert before curr
        curr->setNext(newNode);
    
}

template<class T>
bool List<T>::remove(size_t position)
{

}

template<class T>
T List<T>::getItem(size_t position) const
{

}

template<class T>
void List<T>::clear()
{

}

//insert newNode before curr
//TODO:have we considered the effect of inserting
//a node affecting the current head and/or tail
//curr->setNext

//atleadt 4 statements

    newNode->setPrev(prev);
    //the prev(aka left) neigbhor of newNode is prev
    newNode->setNext(curr);
    //the prev(aka right) neigbhor of newNode is curr
    if (prev != nullptr & curr != nullptr)
    {
        curr->setPrev(newNode);
            //what if curremt is nullptr
            //the prev(aka left) neigbhor of curr is newNode
            //example. if we have no node(in the begining)
            //in the list we insert newNode
            //in this case, prev and curr are both nullptr
            //or if we have 1 node, we want to insert newNode
            //at position 1, then prev is the original head
            //in the current list , and curr is nullptr? 
        prev->setNext(newNode);
            //what is prev is nullptr
            //the prev(aka right) neigbhor of newNode is newNode
    }
    else if (prev == nullptr && curr == nullptr) //next != nullptr
    {
        //in what scenarior will be prev = nullptr and
        //next is not nullptr
    }
    else if (prev == nullptr && curr != nullptr)
    {
        //what scenario do we haev here
        // this woudl be when we insert at the begining of an empty list
        //here pre == nullptr
        //newNode->setNext(curr);
        curr->setPrev(newNode)
        head = newNode;
    }
    else //prev != nullptr && next == nullptr
    {
        
        prev ->setNext(newNode);
        tail = newNode;
    }