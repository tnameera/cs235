//#ifndef DOCTOR_H
//#define DOCTOR_H
#include "person.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Doctor : public Person
{
public:
    Doctor(): Person()// default constructro
    {
        // when a doctor get lichensed he is minimum 30
        set_age(30);
        insurances.push_back("medicare");
        insurances.push_back("medicaid");
    }

    //initialize data with a given name
    Doctor(string name): Person(name,30)//non-default
    {
        
        //set_name(name);
        insurances.push_back("medicare");
        insurances.push_back("medicaid");
    }
    //a doctro with name and age
    Doctor(string name, int age): Person(name,age)
    {
        //set_name(name);
        //set_age(age);
        insurances.push_back("medicare");
        insurances.push_back("medicaid");
    }

    //add insurance coverage
    void add_insurance(string coverage)// no return value
    {
        insurances.push_back(coverage);
        // here we are pushing back the coverage othet 
        //than medicaid and medicare that you want to push 
        //its a string example "united healthcare/ sigma"
    }

    bool accept_insurance(string coverage) const
    {
        //compare the insurance and coverage to see 
        //if the doctor accepts it
        //is the size of insurance is 5 then starting from 0 you shoudl end 
        //your limit at 4, 0-4 counts 5
        //also dont include <= here 
        //bad practice
        for(int i = 0; i < insurances.size(); i++)
            if (insurances[i] == coverage)
                return true;
            return false;
    }

    string to_string() const
    {
        //take the string method from superclass
        string str = "";
        str += "insurnances accepted \n";
        for(int i = 0; i < insurances.size(); i++)
        {
            str += insurances[i];
            if( i != insurances.size() -1)// last insurance of the vectro list
                str += ", ";
        }   

        str += "\n";//else new line
        return str;//return str 
    }

    private:
        vector<string> insurances;
};

void print(Person *individul);

int main()
{
    Person john;
    cout << "info of John" << endl
         << john.to_string() << endl;

    Person john26(26);
    cout << "info of john26" << endl
         << john26.to_string() << endl;

    Person bob("Bob");
    cout << "info of bob" << endl
         << bob.to_string() << endl;

    Person ann("Ann", 20);
    ann.set_age(12);
    ann.set_name("Annie");
    cout << "info of ann" << endl;
    cout << ann.to_string() << endl;

    Doctor family("Ann", 60);
    family.add_insurance("emblem");
    family.add_insurance("blue cross");
    cout << "info of Doctor Ann" << endl;
    cout << family.to_string() << endl;

    //check whether the doctor accepts united health or not.
    //boolalpha means to display true or false value
    //in alpha letters, not just 1 for true or 0 for false.
    cout << boolalpha
         << family.accept_insurance("united") << endl;

    Person *smith = new Person("Abel Smith", 95);
    Doctor *joann = new Doctor("Joann Tom", 36);
    joann->add_insurance("united");

    int SIZE = 2;
    Person* group[SIZE];
    group[0] = smith;
    group[1] = joann;
    for (int i = 0; i < SIZE; i++)
        print(group[i]);

    for (int i = 0; i < SIZE; i++)
    {
        delete group[i];
        group[i] = nullptr;
    }

    return 0;
}

void print(Person* being)
{
    cout << being->to_string() << endl;
}
