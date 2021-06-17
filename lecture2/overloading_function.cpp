#include <iostream>
#include <string>

using namespace std;

void print (int i)
{
    cout << "Printing int: " << i << endl;
}

void print (double f)
{
    cout << "Printing double: " << f << endl;
}

void print (string c)
{
    cout << "Printing character: " << c << endl;
}

int main()
{
    print(4);
    print(2.5);
    print("dog");
}