#include <iostream>
using namespace std;

char add2(char a, char b);

//template can work on any type
//int add(inra, intb)
template<typename T>
T add(T a, T b);


int main()
{   int a =5;
    int b =6;
    cout << add(a, b) << endl;

    double num  =1.6;
    double num2 = 7.8;
    cout << add(num, num2) << endl;

    char ch = '1';
    char ch2 ='2';// ASCII number for 1 + ASCII number for 2 = ASCII number for 3
    cout << add(ch, ch2) << endl;

    cout << add2(ch, ch2) << endl;

    return 0;
}

template<typename T>
T add(T a, T b)
{
    return a + b;
}

//template <>
char add2(char a, char b)
//or char add<char>(char a, char b)
{
    int num = a -'0'; //suppose a is '0'  then a- '0'  is '0'
    // suppose a is '1' then a- '1' is '1'
    int num2 = b - '0';
    int num3 = num + num2;

    //num3 can only be 1-digit integer,
    //since each char is a single character.
    return(char)(num3+ '0');// converting char to number
    //akward result when num3 > = 10
    }


