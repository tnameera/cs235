#include "Duck.hpp"
#include <iostream>
Duck::Duck()// constructor
{
    int pattern[] = { 1,2,-1,5,0};
    int size = sizeof(pattern)/ size of (pattern[0]);
    setPatternAndLength(pattern, size);
    setName("duck");
    setMark('D');
    //Duck duck(pattern, size, 0, "Duck", 'D');
}

Duck::~Duck()//delete distractror
{
 // not dynamic allocated memory to release
}

void Duck::showExcitemetn() const 
{
    cout << "says quack,"; << endl;
}