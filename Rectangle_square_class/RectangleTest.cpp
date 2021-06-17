#include <iostream>
#include "Rectangle.hpp"
#include "Square.hpp"

int main()
{
    Rectangle A(4,5);
    std::cout << A.to_string() << A.getArea()<< std::endl;
    //std::cout << A.getArea()<< std::endl;
    Square B(4);
    std::cout << B.to_string() << B.getArea()<< std::endl;

    //Rectangle B(4,4);
    //std::cout << B.to_string() << std::endl;

    return 0;
}