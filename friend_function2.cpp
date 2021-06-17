#include <iostream>
#include <string>

using namespace std;


class Example{//class A
private:
    int a;

public:
    Example()// constructor to initialize a parameter a
    {
        a = 0;
    } 

    //call friend function
    friend void showEg(Example&); // friend/type of functoin/ name of func/ ref of other function
};


//outside global function  
void showEg(Example& x)
{
    //since showA()is a friend, it can access  private members of Example
    cout << "A::a= " << x.a << endl;
}

int main()
{
    Example eg;// declare object eg
    showEg(eg);
    return 0;

}