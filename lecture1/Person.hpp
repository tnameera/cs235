#ifndef PERSON_H
#define PERSON_H
#include <iostream>

//without the following statement, 
//every occurrence of string needs to write as std::string.
using namespace std; 

class Person
{
public:
    Person();
    Person(string name);
    Person(int age);
    Person(string name, int age);
    string get_name() const;
    int get_age() const;
    void set_name(string name);
    void set_age(int age);
    string to_string() const;

private:
    string name;
    int age;
};
#endif
