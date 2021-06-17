#include "Road.hpp" // include the the h file


//set length to 70
//create an array of 70 chars, put in squares
Road::Road()
{
    length = 70;
    squares = new char [length];
    clear();
}

Road::Road(int len)
{
    if (len <= 0)
        length = 70;
    else length = len;

    squares = new char [length];

    clear(); 

}

Road::~Road()
{
    delete[] squares;
    squares = 0;
}


void Road::clear()
{
    for (int i = 0; i < length; i++)
    {
        squares[i] = ' ';
    }
}

void Road::mark(int pos, char ch)
{
    squares[pos] = ch;
}

int Road::getLastBlock() const
{
    return length -1;
}

char* Road::to_String() const
{
    return squares;
}