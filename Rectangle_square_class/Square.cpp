#include "Square.hpp"
#include <iostream>

Square::Square()//Default constructor
{
    setWidth(0);
    setHeight(0);
}

Square::Square(double side)//non-Default constructor
{
    setWidth(side);
    setHeight(side);
}

Square::~Square()//Default constructor
{
  // not dynamic allocated memory to release  
}

std::string Square::to_string() const
{
    std::string result = "This is a Square:  ";
    return result;
}