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
    //clear every item from the bag,
    //release the dynamic allocated meoery if necessary
    clear();
}

template<class T>
bool LinkedBag<T>::remove(const T& item)
{
    Node<T>* prev = nullptr;//prev is the left neighbor of curr
    Node<T>* curr = head;

    while(curr != nullptr)//curr is not an empty node
    {
        if (curr->getItem() == item)
        {
            //TODO: remove curr
            //prev->next  = curr-> next;
            if (prev == nullptr)//original head is to removed
                head = curr->getNext();
            else
                prev->setNext(curr->getNext());

            //release meomoery allocated to curr
            curr-> setNext(nullptr);
            //next field of curr is not empty yet
            //release the current 
            delete curr;
            curr = nullptr;

            //decrease size by 1
            size--;
            
            //return true
            return true;
        }

        // do i need to update prev?
            prev = curr;
            curr = curr->getNext();//put the right neighbor to curr

    }
    //after finishing searching the list,
    //if no item is found,
    //then we do not return true inside some steps 
    //of the loop.
    //That means, no item in the linked list matches
    //that of given parameter item,
    //so we need to return false after the loop.
    //do i need to update the previous
    return false;
}

template<class T>
bool LinkedBag<T>::isEmpty() const
{
    //if (size == 0)
        //return true
    //else return false;
}

template<class T>
int LinkedBag<T>::getFrequencyOf(const T& item) const
{
    int freq = 0;// we havent traversed the linked bag yet/ seacrched the bag yet
    //look throught the items one by one
    //itterate
    //first item in the loop
    Node<T>*curr = head;//starting point. head is pointer to the node containign data and connecter to the next neighbor
    while(curr != nullptr)
    {
        if(curr->getItem()== item)//as long as their is item which include small node with conents we update the freq
            freq++;

        //if i find no new item move to the next item
        curr = curr->getNext();// basically return next
    }
    return freq;
}

template<class T>
bool LinkedBag<T>::contains(const T& item) const
{
    bool x = getFrequencyOf(item) > 0;
    return x;
   //less item is not there
}

template<class T>
int LinkedBag<T>::getCurrentSize() const
{
    return(size);
    // everytime 1 increase or decrease item wet get size 
    // there is no mishandling of size
    // we have data memeber size
    // we have size in linkedlist

    //incase size is not private
    //int size = 0;
    //Node<T>*curr = head;
    //while(curr != nullptr)
    //{
        //size++;
        //curr = curr->getNext();
    //}
    //return size;  
}

template<class T>
std::vector<T> LinkedBag<T>::toVector() const
{
    std::vector<T>itemVector;//initially empty
    Node<T>*curr = head;

    while(curr != nullptr)
    {
        itemVector.push_back(curr->getItem());
        curr = curr->getNext();
    }
    return itemVector;
}

template<class T>
void LinkedBag<T>::clear()
{
    Node<T>*curr = head;
    while(curr!=nullptr)
    {
        remove(curr->getItem());
        curr = head;
    }
}
