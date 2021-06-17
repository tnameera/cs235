#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>

using namespace std;

class Animal
{
public:
    Animal();
    Animal(int* pattern, int size, int position);
    ~Animal(); //destructor
    void setPatternLength(int* pattern, int size);//done
    void setMark(char mark);//done
    void setName(string name);//done
    void setPosition(int Position);//done
    int* getPattern() const;//done
    int getPatternLength() const;//done
    int getPosition() const; //done
    string getname() const;//done
    char getMark() const;//done
    void move();//done
    virtual void showExcitement() const;//done
    //virtual void makeSound();
   
private:

    int* pattern;
    int  patternLength;
    int  position;
    char mark;

    std::string name;


};
#endif
