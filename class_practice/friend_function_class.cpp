
#include <iostream>
using namespace std;

class Data
{
    private:

    int info;

    public:
    //constructor
        Data()
        {
             info = 0;
        }

        void displayData()
        {
            cout << "info is " << info;
        }

    //prototype or signature
        friend void addValue(Data &d);//add by referenece
};


//outside function access the private data members
void addValue(Data &d)
{
    d.info=d.info+5; 
}


int main()
{
    Data d1;//default info = 0
    d1.displayData();//pass by refernce
    cout << endl;

    //friend function call
    addValue(d1);//pass by refernce
    d1.displayData(); //5
    cout << endl;

    return 0;
}