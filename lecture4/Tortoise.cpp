#include "Tortoise.hpp"
#include <iostream>

Tortoise::Tortoise()// constructor
{
    int pattern[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
    int size = sizeof(pattern)/ sizeof(pattern[0]);
    setPatternLength(pattern, size);
    setName("tortoise");
    setMark('T');
    setPosition(0);
}

Tortoise::Tortoise(std::string name, char mark,int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    setName(name);
    setMark(mark);
    setPosition(position);
}

Tortoise::~Tortoise()//delete distractror
{
 // not dynamic allocated memory to release
}

void Tortoise::showExcitement() const 
{
    cout << " gets it head out" << endl;
}
