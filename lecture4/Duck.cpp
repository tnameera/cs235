#include "Duck.hpp"
#include <iostream>
Duck::Duck()// constructor
{
    int pattern[] = { 1,2,-1,5,0};
    int size = sizeof(pattern)/ sizeof (pattern[0]);
    setPatternLength(pattern, size);
    setName("duck");
    setMark('D');
    //Duck duck(pattern, size, 0, "Duck", 'D');
}

Duck::Duck(std::string name, char mark,int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    setName(name);
    setMark(mark);
    setPosition(position);
}

Duck::~Duck()//delete distractror
{
 // not dynamic allocated memory to release
}

void Duck::showExcitement() const 
{
    cout << "says quack" << endl;
}