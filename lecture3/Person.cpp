#include "Person.hpp"
#include <iostream>
using namespace std;

//Need to be compiled using c++ 11,
//command: g++ -std=c++11 *.cpp
//reason: we use constructor delegation feature,
//which enables one constructor to call another constructor.

//Constructor has exactly the same name as that of class,
//no return type, not even void.
//default constructor is a constructor without any input parameter.
Person::Person()// class:: constructor
{
    name = "John Smith";
    age = 18;
}

//non-default constructor taking an int parameter
Person::Person(int age) : Person()
    //not specify the name but to specify the age so we use set_age
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
//string get_name()const{}
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
    //suppose given parameter name is
    //            1         2
    // "0123456789012345678901234567890"
    // "    firstname    lastname   "
    // then start is 3, which is the index of letter 'f'
    //the first non-space letter in string name
    //end is 22 which is the index of letter 'e'
    //the last non space lette in string name
    //name. substr(start, end-start+1)
    // the first paarmeetr is the start index
    // the second paratmeter ( end-start+1) as the number of letter in the substr
    //we get a substr starting from index (start = 3), with 
    //22-3+1 = 20 letters(= end -start+1) letters
    //so we get substring " firstName   LastName" wihtout quotients
    
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
