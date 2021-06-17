#include "Competition.hpp"
#include <iostream>
#include <iomanip>
#include <vector>


// before you start the project you would like to think what are the date members/ objects involved?
//tortoise, hare and road

    Competition::Competition()// just a single constructor
    {
        rd = new Road;
    }
    Competition::~Competition()//destructor
    {
        delete rd;
        rd = 0;
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
        //how can we find the last block of road object
        int lastBlock = rd-> getLastBlock();
        //keep on running until reaching the last block;
        //as long as not reaching the last block,
        //keep on moving(running)
        int round = 1;//track the number of rounds in total
        bool race_is_still_on = true;
        while (race_is_still_on)

        {  
            // move players
            for (int i = 0; i < players.size(); i++){
                players[i]-> move(); 
                if (players->getPosition() < 0)
                {
                    players[i]->setPosition(0);
                }
                else if (players->getPosition() > lastBlock)
                {
                    players[i]->setPosition(lastBlock); 
                }
            }
            // mark  players
            for (int i = 0; i < players.size(); i++){
                rd->mark(player[i]>getPosition(),' ');
            }
                round++;
                cout << setw(3) << round << ' ';
                cout << track->to_String() << endl;

                for(int i = 0; i < players.size();i++){
                    rd->mark(players[i]->getPosition(),players[i]->getMark());     
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

 