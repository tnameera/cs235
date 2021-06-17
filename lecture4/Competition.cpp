#include "Competition.hpp"
#include <iostream>
#include <iomanip> 
#include <vector>

using namespace std;

Competition::Competition()
{
    rd = new Road;
}

Competition::~Competition()//destructor
{
   
    delete rd;
    rd = nullptr;

}
void Competition::addRoad(int length)// add a road with those many blocks
{
    rd = new Road(length);
    
}
void Competition::addPlayer (Animal*  beast)
{
    players.push_back(beast);
}// we are using pointer as oppose to an object()
//void addlayer (Animal  beast)this would be using object as oppose to pointer
//using object we might loose some data member/member funciton which is included in the subclass 
//eg animals doesnt have all the data member as a sub class Hare
//so using a super class pointer is a much safer choice
//when we use polymorphism we use pointer
void Competition::start()
{
    //vector<Animal*>animal()
    int lastBlock = rd->getLastBlock();
    int round = 1;
    
    bool race_still_going = true;
    while(race_still_going)
    {   
        // move players
        for(int i = 0; i < players.size();i++){
            players[i]->move();
            if(players[i]->getPosition()<0)
            {
                players[i]->setPosition(0);
            }
            else if(players[i]->getPosition()>lastBlock)
            {
                players[i]->setPosition(lastBlock);
            }
        }   

        //mark players
        for(int i = 0; i < players.size();i++){
            rd->mark(players[i]->getPosition(),players[i]->getMark());
        }
        cout << std::setw(3) << round << ' ';
        cout << rd->to_String() << endl;  

        round++;
 
        for(int i = 0; i < players.size();i++){
            rd->mark(players[i]->getPosition(),' ');
        } 

        //check if race is still going
        for(int i = 0; i < players.size();i++){
            if(players[i]->getPosition() >= lastBlock)
            {
                winners.push_back(players[i]);
                race_still_going = false;
            }
        }
    }

    //print winners
    for(int i = 0; i < winners.size();i++){
        cout << winners[i]->getname(); 
        winners[i]-> showExcitement();
        cout << endl;
    }
    cout << endl;
}



