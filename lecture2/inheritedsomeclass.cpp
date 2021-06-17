#include <iostream>
#include <string>

using namespace std;


class SomeClass{//class A
private:
    int memberA;
    int memberB;

public:
    SomeClass(int A = 7, int B = 14)// constructor to initialize a parameter a
    {
        memberA = A;
        memberB = B;
    } 

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

};

//inheritance class
class InheritedSomeClass: public SomeClass // since we are using the public function from the base class called Someclass
{
    public:
        InheritedSomeClass(int A=5, int B=10, int C=15): SomeClass(A,B){
            memberC = C;
        }

        // member function
        bool equals(InheritedSomeClass obj2){
            return ((getMemberA() == obj2.getMemberA()) && (getMemberB() == obj2.getMemberB())&& (memberC == obj2.memberC));
        }// here obj2 is the value 

    private:
        int memberC;
};

int main(){
    //default calling
    InheritedSomeClass object1;
    //non deafult
    InheritedSomeClass object3(5,10,20);

    // call equals member function from inherted class
    bool return1;
    return1 = object1.equals(object3);
    cout << return1 << endl;

    // call equals member function from base class
    return1 = object1.SomeClass::equals(object3);
    cout << return1 << endl;

    return 0;
}