#include "Competition.hpp"
#include "Hare.hpp"
#include "Elephant.hpp"
#include "Tortoise.hpp"
#include "Duck.hpp"
#include <iostream>

int main()
{
    Competition game;
    
    Hare hare;
    game.addPlayer(&hare);
    //use pointer for virtual methid to work

    Tortoise tor;
    game.addPlayer(&tor);

    //for Duck class
    // int pattern[] = { 1,2,-1,5,0};
    // int size = sizeof(pattern)/sizeof(pattern[0]);
    // Duck duck(pattern, size, 0, "Duck", 'D');
    Duck duck;
    game.addPlayer(&duck);

    //for elephant class
    //int pattern2[] = { 1,2,-1};
    //int size = sizeof(pattern2)/sizeof(pattern[0]);
    Elephant elephant;
    game.addPlayer(&elephant);
    
    game.addRoad(16);

    game.start();

    return 0;
}