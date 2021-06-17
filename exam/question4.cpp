
#include <iostream>
using namespace std;


int main()
{
int size = 10;

int* p =  new int(size);

for (int i = size; i > 0; i--)

      p[i] = i;

delete p;

p = nullptr;

return 0;


}