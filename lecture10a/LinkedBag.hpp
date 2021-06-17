#ifndef LINKED_BAG_H
#define LINKED_BAG_H
#include "Node.hpp"
#include <vector>
template<class T>
class LinkedBag
{
public:
    LinkedBag();
    LinkedBag(const LinkedBag<T>& a_bag);
    ~LinkedBag();
    bool add(const T& item);
    bool push_back(const T& item);
    bool remove(const T& item);
    void clear();
    int getCurrentSize() const;
    bool isEmpty() const;
    int getFrequencyOf(const T& item) const;
    bool contains(const T& item) const;
    std::vector<T> toVector() const;
    void reverse();
    LinkedBag<T> get_reverse_list() const;
private:
    Node<T> *head;
    int size; 
};
#include "LinkedBag.cpp" 
//error: write as #include "LinkedBag.hpp"
//in the very beginning, so there is complaint
//Undefined symbols for architecture x86_64
//LinkedBag<int>::add(int const&)
//and so on.
#endif
