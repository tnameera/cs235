#ifndef TEACHER_H
#define TEACHER_H
#include <vector>
#include "Person.hpp"
class Teacher : public Person
{
public:
    Teacher();
    int number_courses();
    int total_credits();
    void add_courses(Course);

private:
    vector<Course> courses;
};


#endif

/*
Class Course
{
    public:
        Course();
        ~Course();
        int getCredits();
        std::string getName();

    private:
        std::string name;
        int credit;
}
*/