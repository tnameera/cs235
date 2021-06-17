#ifndef TORTOISE_H //
#define TORTOISE_H
#include "Animal.hpp"

class Tortoise: public Animal
{
    public:
        Tortoise(); //cosntructor
        Tortoise(int* pattern, int size, int position);
        //note that virtual and overrride only shows 
        //in declaration of methods
        //but not in definition
        // to use ovverside keyword , you need to use c++ 11
        virtual void showExcitement() const override;
};

#endif