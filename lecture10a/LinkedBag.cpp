#include "LinkedBag.hpp"

template<class T>
LinkedBag<T>::LinkedBag()
{
    head = nullptr;
    size = 0;
}

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
  
    //head = nullptr;
    //size = 0;
    //std::vector<T> data = a_bag.toVector();
    //for (int i = data.size()-1; i >= 0; i--)
    //    this->add(data[i]);

    //The above version can be improved.
    //In the above process, toVector traverse the linked bag
    //once, then the for-loop, the linked bag is traversed
    //another time.
    head = nullptr;
    size = 0;
    Node<T>* tail = head;
    Node<T>* curr = a_bag.head;
    Node<T>* newNode;
    while (curr != nullptr)
    {
        //create a node with data from curr, but next is nullptr
        newNode = new Node<T>(curr->getItem());
        if (tail == nullptr) //empty bag
           tail = head = newNode; 
        else { //add newNode to tail
              tail->setNext(newNode);
              tail = tail->getNext();
        }

        curr = curr->getNext();
    }
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
    //Courtsey Michael
//    Node<T>* curr = head;
//    while(curr!=nullptr)
//    { 
//        remove(curr->getItem());     
//        curr = head; 
//    }
    while (head != nullptr)
        remove(head->getItem());
}

template<class T>
bool LinkedBag<T>::push_back(const T& item)
{
    Node<T>* newNode = new Node<T>(item);
    if (newNode == nullptr)
        return false;

    if (head == nullptr) //empty linked list
    {
        head = newNode;
        return true;
    }

    Node<T>* prev = nullptr;
    Node<T>* curr = head;

    //Find out the tail.
    while (curr != nullptr)
    {
        prev = curr;
        curr = curr->getNext();
    }
    prev->setNext(newNode);

    size++;
    return true;
}

//reverse the order of items of linked bag (singly linked list)
template<class T>
void LinkedBag<T>::reverse()
{
//   if (size <= 1) //at most one element
   //(size <= 1) is the same as
   //(head == nullptr || head->getNext() == nullptr)
//      return;
  
   //linked bag, which is an item-order-does-not-matter 
   //singly linked list)
   Node<T>* prev = nullptr; 
   Node<T>* curr = head;

   Node<T>* temp;
   while (curr != nullptr)
   {
       temp = curr->getNext(); //save the next neighbor of curr
       
       //reset the next neighbor of curr to be prev
       curr->setNext(prev);
      
       //prepare for the next prev and curr pairs.
       prev = curr;
       curr = temp;
   }

   head = prev; //new head
}

template<class T>
LinkedBag<T> LinkedBag<T>::get_reverse_list() const
{
    LinkedBag<T> rev_list; //rev_list;

    Node<T>* curr = head;
    while (curr != nullptr)
    {
        rev_list.add(curr->getItem()); 
            //add is insert to head.
        curr = curr->getNext(); 
    }

    return rev_list;
}
