//File name: /Users/laptopuser/Documents/courses/cs235/bag_using_array/LinkedBagTest.cpp
//run the file using g++ LinkedBagTest.cpp
#include <iostream>
#include "LinkedBag.hpp"
//#include "Person.hpp"
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

//    LinkedBag<Person> person_bag;
//    Person ann;
//    Person bob("Bob", 20);
//    person_bag.add(ann);
//    person_bag.add(bob);
//    cout << person_bag.getCurrentSize() << endl;
    //output 2

//    num_bag.clear();
//    cout << "size of num_bag: " << num_bag.getCurrentSize()
//         << endl;
         //output 0

    LinkedBag<int> num_bag2 = num_bag;
     //calling constructor LinkedBag(const LinkedBag<T>&)
     //LinkedBag<int> num_bag(num_bag);
     //Since by previous num_bag.clear() method,
     //num_bag is empty now,
     //so num_bag2 is also empty.

    //add 1, 2, 2 to num_bag
    num_bag.add(1);
    num_bag.add(2);
    num_bag.add(2);
    //remove one occurrence of 2 from num_bag
    num_bag.remove(2);

    cout << "size of num_bag after add 1, 2, 2, then remove 2: " << num_bag.getCurrentSize()
         << endl;

    cout << "size of num_bag 2: " << num_bag2.getCurrentSize()
         << endl;

    cout << "contents of bag 2: " << endl;
    std::vector<int> contentsOfBag2 = num_bag2.toVector();
    for (int i = 0; i < contentsOfBag2.size(); i++)
        cout << contentsOfBag2[i] << endl;
    return 0;
}
