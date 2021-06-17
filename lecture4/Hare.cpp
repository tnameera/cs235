#include "Hare.hpp"
#include <iostream>

Hare::Hare()// constructor
{
    int pattern[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
    int size = sizeof(pattern)/ sizeof (pattern[0]);
    setPatternLength(pattern, size);
    setName("hare");
    setMark('H');
    setPosition(0);
}

Hare::Hare(std::string name, char mark,int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    setName(name);
    setMark(mark);
    setPosition(position);
}

Hare::~Hare()//delete distractror
{
 // not dynamic allocated memory to release
}

void Hare::showExcitement() const 
{
    cout << " move ears" << endl;
}
