//File name: /Users/laptopuser/Documents/courses/cs235/bag_using_array/LinkedBagTest.cpp
//run the file using g++ LinkedBagTest.cpp
#include <iostream>
#include "LinkedBag.hpp"
#include "Person.hpp"
//suppose Person.hpp is put in ../inheritance.
//compile command
//g++ -I ../inheritance -std=c++11 LinkedBagTest.cpp ../inheritance/Person.cpp
using namespace std;

int main()
{
    LinkedBag<int> num_bag;
    num_bag.add(1);
    num_bag.add(2);
    num_bag.add(3);

    cout << num_bag.getCurrentSize() << endl;
        //output 3

    std::cout << std::boolalpha 
        << num_bag.contains(6) << std::endl;
        //output false

    LinkedBag<std::string> name_bag;
    name_bag.add("aaa");
    name_bag.add("bbb");
    name_bag.add("ccc");
    name_bag.add("ddd");
    name_bag.remove("ccc");

    //print
    //aaa bbb ddd
    std::vector<std::string> values = name_bag.toVector();
    for (int i = 0; i < values.size(); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;

    //LinkedBag<Person> person_bag;
    //Person ann;
    //Person bob("Bob", 20);
    //person_bag.add(ann);
    //person_bag.add(bob);
    //cout << person_bag.getCurrentSize() << endl;

    return 0;

    num_bag.clear();
    cout <<" size od num_bag: " << num_bag.getCurrentSize()<< endl;
    //output 0


    //LinkedBag<int>num_bag2 = num_bag;
    //calling this constructor Linkedbag(const Linkedbag<)
    //num_bag.add(1)
    //num_bag.add(2)
    //num_bag.remove(2);
    //cout<<"size of num_bag 2: " << num_bag2.getCurrentSize() << endl; 

}
