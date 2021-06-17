#include "Competition.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

//turtle
Competition::Competition(Hare* hare, Tortoise* tor, int lenth)
{   //initialize data members
    // rabbit = new Hare;//not work , otherwise
    //when destrutor is called
    //delete is not paired with a new
    rabbit = new Hare(hare->getPattern(),hare->getPatternLength(),hare->getPosition());
    //function rabbi news to follow some arguments with parenthesis
    //hare->getpatten() is the same as(*hare).getPattern(),
    //where () around (*hare) cannot be omitted
    //since .operator has higher precedence than *.
    turtle = new Tortoise(tor->getPattern(),tor->getPatternLength(),tor->getPosition());

    track = new Road(lenth);
}
Competition::Competition()
{
    rabbit = new Hare;
    turtle = new Tortoise;
    track = new Road;

}

Competition::~Competition()
{
    delete rabbit;
    rabbit = 0;
    delete turtle;
    turtle = 0;
    delete track;
    track = 0;

}

void Competition::start()
{
    //how can we find the last block of track a road object
    int lastBlock = track-> getLastBlock();

    //keep on running until reaching the last block;
    //as long as not reaching the last block,
    //keep on moving(running)
    int round = 1;//track the number of rounds in total
    bool race_going = true;
    while (race_going)
           {
                rabbit-> move();
                //make sure the rabbit does not run off the track.
                //that is , not going to be negative block;
                //or surpass the last block
                //when we take a picture of the road
                //we cannt see the the animal
                if (rabbit->getPosition() < 0)
                    rabbit->setPosition(0);

                else if (rabbit->getPosition() > lastBlock)
                    rabbit->setPosition(lastBlock); 

                // turtle
                turtle-> move();
                //make sure the rabbit does not run off the track.
                //that is , not going to be negative block;
                //or surpass the last block
                //when we take a picture of the road
                //we cannt see the the animal
                if (turtle->getPosition() < 0)
                    turtle->setPosition(0);

                else if (turtle->getPosition() > lastBlock)
                    turtle->setPosition(lastBlock); 
                
                track->mark(rabbit->getPosition(),'H');
                track->mark(turtle->getPosition(),'T');
                cout << setw(3) << round << ' ';
                cout << track->to_String() << endl;

                round++;
                track->mark(rabbit->getPosition(),' ');
                track->mark(turtle->getPosition(),' ');
               
               if (rabbit->getPosition() >= lastBlock ||
                   turtle->getPosition() >= lastBlock){
                   race_going = false;
               }
           }

            if (rabbit->getPosition() < lastBlock)
                cout << "Yay!!! tortoise wins!";
            else
                cout << "Yuck, hare wins.";
            cout << endl;
}
