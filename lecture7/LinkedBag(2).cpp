#include "LinkedBag.hpp"

template<class T>
LinkedBag<T>::LinkedBag()
{
    head = nullptr;
    size = 0;
}

//TODO
template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag)
{
    //shallow copy, problem: when a destructor is called,
    //an item in the linked bag is released more than once,
    //even though that item is applied through new operator
    //for only once.
    //head = a_bag.head;
    //size = a_bag.size;

    //need to make a deep copy.
    //courtesy Alan Hu
    //we can make a vector, 
    //reverse the vector (since we add items to the head),
    //then add items in vector to the bag
  
    head = nullptr;
    size = 0;
    std::vector<T> data = a_bag.toVector();
    for (int i = data.size()-1; i >= 0; i--)
        this->add(data[i]);
}

template<class T>
LinkedBag<T>::~LinkedBag()
{
    clear(); //clear every item from the bag,
    //release dynamic allocated memory if necessary.
}

template<class T>
bool LinkedBag<T>::add(const T& item)
{
    //The order of items of a bag is not important,
    //so we can add the item to the front of the linked list.

    //apply for space to hold a node whose data is
    //item and whose next neighbor info is nullptr,
    //afterward, reset next field of newNode to be 
    //original head. This is like to add item to the head.
    //Node<T>* newNode = new Node<T>(item, nullptr);
    //newNode->setNext(head);

    //The above code has the same effect as follows,
    //where next field of node is specified as
    //the original head directly.
    Node<T>* newNode = new Node<T>(item, head);
    if (newNode == nullptr)
       return false;

    //add a funciton push_back to add a item at the tail
    // Node<T>* newNode = new Node<T>(item, head);
    // using namespace std;
    // vector<int> v = {1, 3, 4};
    //while (newNode != nullptr)
    // v.push_back(item);
    // // item now contains {1, 2, 3, 4, 5}

    //newNode is not nullptr, it has data saved in item_
    //data member, and head saved in next_ data member.
    //See code of Node.cpp.

    //newNode becomes the head.
    head = newNode;

    size++;
    return true;
}

template<class T>
bool LinkedBag<T>::remove(const T& item)
{
    Node<T>* prev = nullptr; //prev is the left neighbor of curr
    Node<T>* curr = head;

    while (curr != nullptr) //curr is not an empty node
    {
        if (curr->getItem() == item)
        {
           //TODO: remove curr.
           //pseucode code: prev->next = curr->next;
           if (prev == nullptr) //original head is to removed
              head = curr->getNext(); 
           else prev->setNext(curr->getNext());

           //release memory allocated to curr.
           curr->setNext(nullptr); 
              //next field of curr is not empty yet.
           delete curr;
           curr = nullptr;

           //decrease size by 1.
           size--;

           //return true;
           return true;
        }

        //do I need to update prev?
        prev = curr;
        curr = curr->getNext(); //put the right neighbor
        //to curr
    }
   
    //after finishing searching the list,
    //if no item is found,
    //then we do not return true inside some steps 
    //of the loop.
    //That means, no item in the linked list matches
    //that of given parameter item,
    //so we need to return false after the loop.
    return false;
}

template<class T>
bool LinkedBag<T>::isEmpty() const
{
    //if (size == 0)
    //   return true;
    //else return false;

    return head == nullptr; //same as return size == 0;
}

template<class T>
int LinkedBag<T>::getFrequencyOf(const T& item) const
{
    int freq = 0; //we have not searched the linked bag yet.
    Node<T>* curr = head;
    while (curr != nullptr)
    {
        if (curr->getItem() == item) 
           freq++;

        curr = curr->getNext();
    }

    return freq;
}

template<class T>
bool LinkedBag<T>::contains(const T& item) const
{
    return getFrequencyOf(item) > 0; 
}

template<class T>
int LinkedBag<T>::getCurrentSize() const
{
    return size;         
}

template<class T>
std::vector<T> LinkedBag<T>::toVector() const
{
    std::vector<T> itemVector;
    Node<T>* curr = head;

    while (curr != nullptr)
    {
	itemVector.push_back(curr->getItem());
	curr = curr->getNext(); 
    }

    return itemVector;
}

template<class T>
void LinkedBag<T>::clear()
{
    //Node<T>* curr = head;
    //while(curr!=nullptr)
    //{ 
    //    remove(curr->getItem());     
    //    curr = head; 
    //}
    while(head != nullptr)
    {
        remove(head->getItem());
    }
}
