#include "Elephant.hpp"
#include <iostream>

Elephant::Elephant()// constructor
{
    int pattern[] = {1, 2, -2};
    int size = sizeof(pattern)/ size of (pattern[0]);
    setPatternAndLength(pattern, size);
    setName("elephant");
    setMark('E');
}

Elephant::~Elephant()//delete distractror
{
 // not dynamic allocated memory to release
}

void Elephant::showExcitement() const 
{
    cout << " extends nose "; << endl;
}