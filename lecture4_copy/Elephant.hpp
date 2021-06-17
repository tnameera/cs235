#ifndef ELEPHANT_H //
#define ELEPHANT_H
#include "Animal.hpp"

class Elephant: public Animal
{
    public:
        Elephant(); //cosntructor
        //note that virtual and overrride only shows 
        //in declaration of methods
        //but not in definition
        // to use ovverside keyword , you need to use c++ 11
        virtual void showExcitement() const override;
};

#endif