#include "Doctor.hpp"
#include <iostream>
using namespace std;

Doctor::Doctor() : Person()
{
    //Person(); //does not work
    set_age(30); //normally when a doctor gets license, 
       //he/she will be close to 30s.
       //subclass can call super class's public methods.
    insurances.push_back("medicare");
    insurances.push_back("medicade");
}

//initialize data with the given name
Doctor::Doctor(string name) : Person(name, 30)
{
    //Person(name, 30); //does not work
    insurances.push_back("medicare");
    insurances.push_back("medicade");
}

Doctor::Doctor(string name, int age) : Person(name, age)
{
    //Person(name, age); //does not work
    insurances.push_back("medicare");
    insurances.push_back("medicaid");
}

void Doctor::add_insurance(string coverage)
{
    insurances.push_back(coverage);
}

bool Doctor::accept_insurance(string coverage) const
{
    for (int i = 0; i < insurances.size(); i++)
        if (insurances[i] == coverage)
           return true;

    return false;
}

string Doctor::to_string() const 
{
    string str = Person::to_string(); 
        //take to_string method from superclass
        //without Person:: before to_string(),
        //you are call method to_string() itself
        //infinitely many times, memory will be exhausted,
        //you will get an error like "command terminated".
    str += "insurances accepted\n";
    for (int i = 0; i < insurances.size(); i++)
    {
        str += insurances[i];
        if (i != insurances.size() -1)
           str += ", ";
    }

    str += "\n";
    return str;
}
