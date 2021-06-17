
#include <iostream>
using namespace std;

class Person
{
public:
    Person(){
        name = " john smith";
        age =18;
    }
    Person(string name): Person() //without using namespace std;
    //which needs to be paired with #include <iostream>,
    //when we use string, we need to use std::string,
    //Or, when we use endl, we need to use std::endl.
    {
        set_age(age);
    }

    Person(int age): Person()//constructor using the base constructro
    {
        set_name(name);
    }

    Person(string name, int age): Person()
    {
        set_name(name);
        set_age(age);
    }


    string get_name() const // string functions
    // the are accessor they dont change just reuturn value of some private member
    {
        return name;
    }

    int get_age() const
    {
        return age;
    }

    void set_name(string name)// void dont return function just for print/override/update
    {
        size_t start = name.find_first_not_of(" ");
        size_t last = name.find_last_not_of(" ");

        //first paraemeter of substr is start index,
        //second parameter of substr is length of substring 
        name = name.substr(start, last - start+1);
        if (name != "")
            this->name = name;
    }
    void set_age(int age)
    {
        //human being's valid age is [0, 120].
        if (age >= 0 && age <= 120)
            this->age = age;
    }

    virtual string to_string() const// we can have multiple use of this file
    {   string str = "";
    str += "name: " + name + "\n";
    //to_string(age) convert int type variable age
    //to corresponding string.
    //Suppose age is 7, then to_string(age) returns "7".
    str += "age: " + std::to_string(age) + "\n";
    
    return str;

    }
private:
    string name;
    int age;
};