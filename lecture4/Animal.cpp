#include "Animal.hpp"
#include <iostream>

using namespace std;

Animal::Animal()// constructor
{
    int pattern[] = {1, 2, -2};
    int size = sizeof(pattern)/ sizeof (pattern[0]);
    setPatternLength(pattern, size);
    setName("Animal");
    setMark('A');
}

Animal::Animal(std::string name, char mark,int* pattern, int size, int position)// constructor
{
    setPatternLength(pattern, size);
    //setName("Animal");
    //setMark('A');
}

Animal::~Animal()
{
    
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
    int index = rand() % patternLength;
    int stepsToMove = pattern[index];
    position = position + stepsToMove;
    
}

char Animal::getMark() const
{
    return mark;
}

string Animal::getname() const //please verify
{
    return name;
}
//set functions

void Animal::setName(std::string newName)
{
    name = newName;
}

void Animal::setMark(char newMark)
{
    mark = newMark;
}


void Animal::setPatternLength(int* pattern, int size)
    
{
    (*this).patternLength = size > 0 ? size : 10;
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
    cout << " happy voice " << endl;
}


