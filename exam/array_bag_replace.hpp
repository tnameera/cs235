#ifndef ARRAY_BAG_H_
#define ARRAY_BAG_H_

template<class T>
class ArrayBag
{
//class declaration here
public:
    ArrayBag();
    //ArrayBag(int capacity); 

    ~ArrayBag();

    //Task: reports the current index of ArrayBag
    //Input: none
    //Output: the item currently in ArrayBag
    int getIndex() const;

    //Task: checks whether ArrayBag is empty
    //Input: none
    //Output: true or false according to whether ArrayBag is empty
    bool isEmpty() const;

    //Task: removes an object from the ArrayBag
    //Input: an_entry is an object
    //Output: true or false according to 
    //whether removal succeeds
    bool remove(const T& an_entry);

    //Task: adds a given object to the ArrayBag
    //Input: new_entry is an object
    //Output: true or false according to 
    //whether addition succeeds
    bool add(const T& new_entry);

    //Task: removes all objects from the ArrayBag
    //Input: none
    //Output: none
    void clear();


