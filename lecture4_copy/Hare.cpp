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

Hare::Hare(int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    setName("hare");
    setMark('H');
    setPosition(position);
}

void Hare::showExcitement() const 
{
    cout << " move ears" << endl;
}
