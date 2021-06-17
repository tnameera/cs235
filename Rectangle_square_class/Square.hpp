//inheretance class
#ifndef SQUARE_H //
#define SQUARE_H
#include "Rectangle.hpp"

class Square : public Rectangle
{
    public:
        Square();
        Square(double side);
        ~Square(); //destructor
        virtual std::string to_string() const;
        //virtual setwidth(width) override;
        //virtual setheight(height) override;
};
#endif
    



