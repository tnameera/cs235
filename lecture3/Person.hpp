#ifndef PERSON_H //include guard
#define PERSON_H
#include <iostream>

//without the following statement, 
//every occurrence of string needs to write as std::string.
using namespace std; 

class Person
{
public:
    Person();
    Person(string name); //without using namespace std;
    //which needs to be paired with #include <iostream>,
    //when we use string, we need to use std::string,
    //Or, when we use endl, we need to use std::endl.
    Person(int age);
    Person(string name, int age);
    string get_name() const;
    int get_age() const;
    void set_name(string name);
    void set_age(int age);
    virtual string to_string() const;// we can have multiple use of this file

private:
    string name;
    int age;
};
#endif
