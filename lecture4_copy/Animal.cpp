#include "Animal.hpp"
#include <iostream>

Animal::Animal()// constructor
{
    int pattern[] = {1, 2, -2};
    int size = sizeof(pattern)/ size of (pattern[0]);
    setPatternLength(pattern, size);
    setName("Animal");
    setMark('A');
}

Animal::Animal(int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    setName("Animal");
    setMark('A');
}

Animal::~Animal()
{
    delete[] pattern;
    pattern = 0; //set pattern to be nullptr
}

int Animal::getPosition() const
{
    return position; 
}

int* Animal::getPattern() const
{
    return pattern;
}

int Animal::getPatternLength() const
{
    return patternLength;
}

void Animal::setPosition(int newPosition)
{
    position = newPosition;
}

void Animal::move()
{
    int index = rand() % length;
    int stepsToMove = pattern[index];
    position = position + stepsToMove;
    
}

char Animal::getMark() const
{
    return mark;
}

std::string getname() const//please verify
{
    return name;
}
//set functions

void Animal::setPosition(int newPosition)
{
    position = newPosition;
}

void Animal::setName(std::string newName)
{
    name = newName;
}

void Animal::setMark(char newMark)
{
    mark = newMark;
}


void Animal::setPatternLength(int* pattern, int size) : 
    patternLength(size > 0 ? size : 10)
{
    (*this).pattern = new int[patternLength];
    if(size > 0)
        for (int i = 0; i < size; i++)
            this->pattern[i] = pattern[i];
    else //size<=0
    {
        int defaultPattern[] = 
            {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
        for (int i = 0; i < patternLength; i++)
            this->pattern[i] = defaultPattern[i];
    }

}

void Animal::showExcitement() const
{
    cout << " happy voice "; << endl;
}


