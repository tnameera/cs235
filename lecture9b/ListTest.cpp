//File name: /Users/laptopuser/Documents/courses/cs235/list/ListTest.cpp
#include <iostream>
#include "List.hpp" 
using namespace std;

void print(List<int> a_list);

int main()
{
    List<int> num_list;
    num_list.insert(0, 5); //1
    num_list.insert(1, 11); //1->2
    num_list.insert(1, 8); //1->2
    num_list.insert(1, 6); //1->2
    num_list.insert(1, 1); //1->3->2

    cout << num_list.getLength() << endl; 
        //List 1->3->2 has 3 elements. Print 3.
        //////////////////l
    //int list_n  = num_list.getLength();
    for (int i = 0; i < num_list.getLength(); i++)
    {   
        cout << "i: " << i << endl; 
        num_list.remove(0); //delete the first item

        cout << endl;
    }
    cout << num_list.getLength() << endl; 
    ///////////

    for (int i = 0; i <= num_list.getLength(); i++)
        cout << num_list.getItem(i) << " ";

    num_list.insert(0, 6); //6->1->3->2
    try {
         for (int i = 0; i <= num_list.getLength(); i++)
             cout << num_list.getItem(i) << " ";

         cout << endl;
    }
    //If we use the following statement in try-block,
    //   for (int i = 0; i <= num_list.getLength(); i++)
    //       cout << num_list.getItem(i) << " ";
    //Then, when i == num_list.getLength(), 
    //an out_of_range exception is thrown out,
    //then we catch it in catch block,
    //and print out the error message.
    catch (out_of_range* p) 
    {
        cout << p->what() << endl;
    }

    List<int> reverse_num_list = num_list.get_reverse_list();
    cout << "the reversed list of num list, num list is not changed: " << endl;
    print(reverse_num_list);

    //the current linked list is 6->1->3->2.
    //we want to reverse it.
    num_list.reverse();

    cout << "num list after reversion: " << endl;
    print(num_list);

    for (int i = 0; i < num_list.getLength(); )// i++)
    {
        num_list.remove(0); //delete the first item

        //for (int j = 0; j < num_list.getLength(); j++)
        //    cout << num_list.getItem(j) << " " ;
        //cout << endl;
        print(num_list);
    }

    return 0;
}

void print(List<int> a_list)
{
    for (int i = 0; i < a_list.getLength(); i++)
        cout << a_list.getItem(i) << " ";
    cout << endl;
}
