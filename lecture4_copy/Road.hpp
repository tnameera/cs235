#pragma once
#ifndef ROAD_H //include guard or header guard
#define ROAD_H

//Header guards are designed to ensure that the contents of a given header file are not copied, more than once,
class Road
{
public:
    Road();
    Road(int length);
    ~Road(); //destructor
    //clear each block of the road to be a space char
    //it is equilavalent to clean the road
    //this method i scalled by constructors
    void clear();
    void mark(int pos, char ch);// modify every square of the road
    int getLastBlock() const; //modify tell me how many blocks of road
    //suppose the first block starts at 0 
    //get the last block of the road
    //array string
    // Returns a char array to represent the contents
    // of blocks of the road object
    char* to_String() const;    
   
private:
    char* squares;
    int length;
}; 
#endif 
