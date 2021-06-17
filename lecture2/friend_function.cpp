#include <iostream>
#include <string>

using namespace std;


class A{//class A
private:
    int a;

public:
    A()// constructor to initialize a parameter a
    {
        a = 0;
    } 

    //call friend function
    friend void showA(A&); // friend/type of functoin/ name of func/ ref of other function
};

void showA(A& x)
{
    //since showA()is a friend, it can access  private members of A
    cout << "A::a= " << x.a << endl;
}

int main()
{
    A a;
    showA(a);
    return 0;

}