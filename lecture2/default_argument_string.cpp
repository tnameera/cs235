#include <iostream>
#include <string>

using namespace std;

void Animal(string name) //or void Animal(string name = "")
{
    cout << name << endl;
} 

int main()
{
    Animal("dog"); 
    //string s; s by deafult is an empty string
}