#include <iostream>
#include "Competition.hpp"// include Animal
#include "Hare.hpp"// Hare
#include "Tortoise.hpp"// Tortoise
#include "Duck.hpp"// Duck
#include "Elephant.hpp"// Elephant
using namespace std;

class Runcomepition: public Animal
{
    public:
    Runcomepition(), //constructor
    //note that virtual and overrride only shows 
    //in declaration of methods
    //but not in definition
    // to use ovverside keyword , you need to use c++ 11
    virtual void showExcitement() const
};


#endif