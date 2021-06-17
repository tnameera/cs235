#ifndef HARE_H //
#define HARE_H
#include "Animal.hpp"

class Hare: public Animal
{
    public:
        Hare(); //cosntructor
        Hare(int* pattern, int size, int position);
        //note that virtual and overrride only shows 
        //in declaration of methods
        //but not in definition
        // to use ovverside keyword , you need to use c++ 11
        virtual void showExcitement() const override;
};

#endif
