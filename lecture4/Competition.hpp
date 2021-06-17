#ifndef COMPETITION_H //
#define COMPETITION_H
#include "Animal.hpp"
#include "Road.hpp"
#include <vector>


// before you start the project you would like to think what are the date members/ objects involved?
//tortoise, hare and road

class Competition
{

public:
    Competition();
    ~Competition();//destructor
    void addRoad(int length);// add a road with those many blocks
    void addPlayer (Animal*  beast);// we are using pointer as oppose to an object()
    //void addlayer (Animal  beast)this would be using object as oppose to pointer
    //using object we might loose some data member/member funciton which is included in the subclass 
    //eg animals doesnt have all the data member as a sub class Hare
    //so using a super class pointer is a much safer choice
    //when we use polymorphism we use pointer
    void start();

    // Competition(Hare* hare, Tortoise* tor, int lenth);
    // std:: string getname() const;
    // char getMark() const;
    // void setPatternAndLength(int* pattern, int size);
    // virtual void showExcitement() const;
    //void start();//or can say play/start
    //dont forget

private:
    // Hare* rabbit;//otherwise to disntict class and object use diff name
    // Tortoise* turtle;//if no * then it will be object and take more space
    // Road* track;
    std::vector<Animal*> players;//vector to animal poinetrs. aniamal pointer is a pointer to animal object
    std::vector<Animal*> winners;// here variable for winner is decalred and intsantiated
    Road* rd;

};
#endif