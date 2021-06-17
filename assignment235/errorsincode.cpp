
#include <iostream>
using namespace std;

void someFunction(){
    int* p = new int[5];
    int* q = new int[10];
    p[2] = 9;
    q[2] = p[2]+5;
    p[0] = 8;
    q[7] = 15;
    std::cout<< p[2] << " " << q[2] << std::endl; 
    q = p;
    std::cout<< p[0] << " " << q[7] << std::endl;
    delete[] p;
    p = nullptr;
}

int main()
{ 
    someFunction();
    return 0;
}