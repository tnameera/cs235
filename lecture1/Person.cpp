#include "Person.hpp"
#include <iostream>
using namespace std;

//Need to be compiled using c++ 11,
//command: g++ -std=c++11 *.cpp
//reason: we use constructor delegation feature,
//which enables one constructor to call another constructor.

//Constructor has exactly the same as a class,
//no return type, not even void.
//default constructor is a constructor without any
//input parameter.
Person::Person()
{
    name = "John Smith";
    age = 18;
}

//non-default constructor taking an int parameter
Person::Person(int age) : Person()
    //Person::Person(int age) : Person() 
    //means non-default constructor Person(int)
    //calls default constructor Person().
    //This is called constructor delegation,
    //which means a constructor calls another constructor.
    
    //Person() is like to have a table with 
    //some pre-filled (deault) data.
{
   
    //Change the data of data member age 
    //if given parameter age is appropriate.
    set_age(age);
}

//non-default constructor taking a string parameter
Person::Person(string name) : Person()
{
    set_name(name);
}

Person::Person(string name, int age) : Person()
{
    set_name(name);
    set_age(age);
}

//accessor (also called getter) to return data member age
string Person::get_name() const
{
    return name;
}

//accessor (also called getter) to return data member age
int Person::get_age() const
{
    return age;
}

void Person::set_age(int age)
{
    //human being's valid age is [0, 120].
    if (age >= 0 && age <= 120)
       this->age = age;
    //if given parameter is not in [0, 120],
    //just ignore the request to reset data member age.
    //When data member and age have exactly
    //the same name, add this-> before data member age
    //to distinct data member age and given parameter age.
}

//As long as name contains some non-space letter,
//use it to reset data member name.
void Person::set_name(string name)
{
    //remove leading and trailing spaces of name
    //Google "c++ trim string" 
    //https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
    size_t start = name.find_first_not_of(" ");
    size_t last = name.find_last_not_of(" ");

    //first paraemeter of substr is start index,
    //second parameter of substr is length of substring 
    name = name.substr(start, last - start+1);
    if (name != "")
       this->name = name;
}

//return a textual representation of key information of Person
string Person::to_string() const
{
    string str = "";
    str += "name: " + name + "\n";
    //to_string(age) convert int type variable age
    //to corresponding string.
    //Suppose age is 7, then to_string(age) returns "7".
    str += "age: " + std::to_string(age) + "\n";
    
    return str;
}
