//File name: /Users/laptopuser/Documents/courses/cs235/inheritance/PersonTest.cpp
#include <iostream>
#include "Person.hpp"
#include "Doctor.hpp"
using namespace std;

void print(Person *individul);

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
    cout << "info of ann" << endl;
    cout << ann.to_string() << endl;

    Doctor family("Ann", 60);
    family.add_insurance("emblem");
    family.add_insurance("blue cross");
    cout << "info of Doctor Ann" << endl;
    cout << family.to_string() << endl;

    //check whether the doctor accepts united health or not.
    //boolalpha means to display true or false value
    //in alpha letters, not just 1 for true or 0 for false.
    cout << boolalpha
         << family.accept_insurance("united") << endl;

    Person *smith = new Person("Abel Smith", 95);
    Doctor *joann = new Doctor("Joann Tom", 36);
    joann->add_insurance("united");

    int SIZE = 2;
    Person* group[SIZE];
    group[0] = smith;
    group[1] = joann;
    for (int i = 0; i < SIZE; i++)
        print(group[i]);

    for (int i = 0; i < SIZE; i++)
    {
        delete group[i];
        group[i] = nullptr;
    }

    return 0;
}

void print(Person* being)
{
    cout << being->to_string() << endl;
}
