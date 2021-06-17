//File name: /Users/laptopuser/Documents/courses/cs235/bag_using_array/ArrayBagTest.cpp
//run the file using g++ ArrayBagTest.cpp
#include <iostream>
#include "ArrayBag.hpp"

//suppose Person.hpp is put in ../inheritance.
//compile command
//g++ -I ../inheritance -std=c++11 ArrayBagTest.cpp ../inheritance/Person.cpp
//using namespace std;

int main()
{
    ArrayBag<int> num_bag;
    for (int i = 1; i <= 16; i++)
        num_bag.add(i);
    
    std::cout << std::boolalpha; 
    std::cout << num_bag.add2(5)<< std::endl;
    std::cout << num_bag.add2(17)<< std::endl;  
     
        
    //num_bag.add(1);
    //num_bag.add(3);
    //num_bag.add(5);
        

    std::cout << num_bag.getCurrentSize() << std::endl;
        //output 3

    std::cout << std::boolalpha 
        << num_bag.contains(6) << std::endl;
        //output false
    std::cout << std::boolalpha 
        << num_bag.replace(3,2) << std::endl; 

    ArrayBag<std::string> name_bag;
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

    //ArrayBag<Person> person_bag;
    //Person ann;
    //Person bob("Bob", 20);
    //person_bag.add(ann);
    //person_bag.add(bob);
    //cout << person_bag.getCurrentSize() << endl; //output 2

    //person_bag.remve(ann);
    //cout << person_bag.getCurrentSize() << endl;//output 1

    //Person cat;
    //person_bag.remove(cat);
    //cout << person_bag.getCurrentSize() << endl;


    return 0;
}
