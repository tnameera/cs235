#include <iostream>
#include <string>

using namespace std;


class SomeClass{//class A
private:
    int memberA;
    int memberB;

public:
    SomeClass()// default constructor to initialize a parameter a
    {
        memberA = 0;
        memberB = 0;
    } 

    SomeClass(int A, int B)// non-defsult constructor to initialize a parameter a
    {
        memberA = A;
        memberB = B;
    } 

    //SomeClass(int memberA, int memberB)// non-defsult constructor to initialize a parameter a
    //{
    //    this->memberA = memberA;
    //    this->memberB = memberB;
    //} 

    // member function
    bool equals(SomeClass obj2){
        return ((memberA == obj2.memberA) && (memberB == obj2.memberB));
    }

    //member function add
    int add(SomeClass obj3){
        return((memberA + obj3.memberA));
    }
    
    int getMemberA() const //accesor functions
    {
        return (memberA);
    }

    int getMemberB() const //accesor functions
    {
        return (memberB);
    }

    //friend function
    friend bool operator==(SomeClass obj1, SomeClass obj2);

    //friend function
    friend bool equal3(SomeClass obj1, SomeClass obj2);

    //friend 3 function
    friend int add3(SomeClass obj1, SomeClass obj2);

    //friend 3 function over loading
    friend int add3(SomeClass obj1);
};

bool operator==(SomeClass obj1, SomeClass obj2){
    return ((obj1.memberA == obj2.memberA) && (obj1.memberB == obj2.memberB));
}

// friend function
bool equal3(SomeClass obj1, SomeClass obj2){
    return ((obj1.memberA == obj2.memberA) && (obj1.memberB == obj2.memberB));
}

//add function
int add3(SomeClass obj1, SomeClass obj2){
    return(obj1.memberA + obj2.memberA);
}

//add function overloading
int add3(SomeClass obj1){
    return(obj1.memberA + 3);
}

//inheritance class
class InheritedSomeClass: public SomeClass
{
    public:
        InheritedSomeClass(int A=5, int B=10, int C=15): SomeClass(A,B){
            memberC = C;
        }

    private:
        int memberC;
};

int main(){
    SomeClass object10, object20;
    // object10 has memberA=0 and memberB=0
    SomeClass object30(5,10);
    bool result;
    result = object10.equals(object20);
    cout << result << endl;
    //add object30 to object20
    int result1;
    result1 = object20.add(object30);
    cout << result1 << endl;
    // friend funciton add just member A
    cout << add3(object20,object30)<< endl;
    //overloading add3
    cout << add3(object20)<< endl;
    //cout << (object10 == object20) << endl;
    cout << equal3(object10, object20) << endl;
    result = object30.equals(object20);
    cout << result << endl;
    //cout << (object30 == object20) << endl;
    cout << equal3(object30, object20) << endl;
    return 0;
}