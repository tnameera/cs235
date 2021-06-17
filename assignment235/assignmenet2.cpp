
//In LinkedBag class discuss today, add a function push_back function that add an item to the tail (not to the head). 
//Suppose data members are still head and size.
template<class T>
bool LinkedBag<T>::push_back(const T& item)
{

    Node<T>* newNode = new Node<T>(item);
    if (newNode == nullptr)
        return false;

    Node<T>* curr = head;
    while (curr != nullptr)
    {
	    curr = curr->getNext(); 
    }
    curr->setNext(newNode);
    return true;

}
