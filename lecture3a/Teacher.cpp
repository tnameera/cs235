include "Teacher.hpp"
#include <iostream>

Teacher::Teacher() : Person()
{

}

void add_courses(Course course1)
{
    courses.push_back(course1);
}

int number_courses()
{
    return (courses.size())
}
    
int total_credits()
{
    int total_credits = 0;
    for(int i = 0; i < courses.size(); i++)
    {
        total_credits += courses[i]->getCredits();
    }

    return (total_credits);
}