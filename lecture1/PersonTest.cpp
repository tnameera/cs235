//File name: /Users/laptopuser/Documents/courses/cs235/inheritance/PersonTest.cpp
#include <iostream>
#include "Person.hpp"
using namespace std;

int main()
{
    Person john;
    cout << "info of John" << endl
         << john.to_string() << endl;

    Person john26(26);
    cout << "info of john26" << endl
         << john26.to_string() << endl;

    Person bob("Bob");
    cout << "info of bob" << endl
         << bob.to_string() << endl;

    Person ann("Ann", 20);
    ann.set_age(12);
    ann.set_name("Annie");
    cout << "info of ann" << endl
         << ann.to_string() << endl;

    return 0;
}
