//File name: /Users/laptopuser/Documents/courses/cs235/list/ListTest.cpp
#include <iostream>
#include "List.hpp" 
using namespace std;

int main()
{
    List<int> num_list;
    num_list.insert(0, 1);
    num_list.insert(1, 2);
    num_list.insert(1, 3);


    cout << num_list.getLength() << endl;
    for (int i = 0; i < num_list.getLength(); i++)
    {
        num_list.remove(0); //delete the first item
        
    }
    cout << num_list.getLength() << endl;

    num_list.insert(0, 6);
    try {
         for (int i = 0; i < num_list.getLength(); i++)
             cout << num_list.getItem(i) << " " ;
    }
    catch (const out_of_range* error) 
        //we use new when throwing out an exception
    {
        cerr << "\nout of range: " << error->what() << endl; 
    }
    catch (...)
    {
        cerr << "uncaught exception." << endl;
    }
    cout << endl;
    
    return 0;
}
