#ifndef ARRAY_BAG_H_
#define ARRAY_BAG_H_
#include <vector> //use vector class in toVector method
template<class T>
class ArrayBag //ArrayBag is a class template
{
//class declaration here
public:
    ArrayBag();
    //ArrayBag(int capacity); 

    ArrayBag(int arr[], int newSize);

    ~ArrayBag();

    //Task: reports the current number of objects in ArrayBag
    //Input: none
    //Output: the number of objects currently in ArrayBag
    int getCurrentSize() const;

    //Task: checks whether ArrayBag is empty
    //Input: none
    //Output: true or false according to whether ArrayBag is empty
    bool isEmpty() const;
    
    //Task: replace a given object to the ArrayBag
    //Input: new_entry is an object
    //Output: true or false according to 
    //whether replace succeeds
    bool replace(const T& piece,const T& new_piece );

    //Task: adds a given object to the ArrayBag
    //Input: new_entry is an object
    //Output: true or false according to 
    //whether addition succeeds
    bool add(const T& new_entry);

    //Task: removes an object from the ArrayBag
    //Input: an_entry is an object
    //Output: true or false according to 
    //whether removal succeeds

    bool add2(const T& piece);

    bool addNoDuplicates(const T& piece);

    bool remove(const T& an_entry);

    //Task: removes all objects from the ArrayBag
    //Input: none
    //Output: none
    void clear();

    //Task: counts the number of times an object occurs in ArrayBag
    //Input: an_entry is an object
    //Output: the int number of times an_entry occurs in ArrayBag
    int getFrequencyOf(const T& an_entry) const;

    //Task: checks whether ArrayBag contains a particular object
    //Input: an_entry is an object
    //Output: true of false according to 
    //whether an_entry is in ArrayBag
    bool contains(const T& an_entry) const;

    //Task: gets all objects in ArrayBag
    //Input: none
    //Output: a vector containing all objects currently in ArrayBag
    std::vector<T> toVector() const;

    bool removeRandom();

private:
    T* items;
    int size;
    int capacity;
};
#include "ArrayBag.cpp"
#endif
