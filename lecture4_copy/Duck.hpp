#ifndef DUCK_H //
#define DUCK_H
#include "Animal.hpp"

class Duck:public Animal
{
    public:
        Duck(); //cosntructor
        //note that virtual and overrride only shows 
        //in declaration of methods
        //but not in definition
        // to use ovverside keyword , you need to use c++ 11
        virtual void show Excitement() const override;
};

#endif