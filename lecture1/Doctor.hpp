#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include "Person.hpp"
class Doctor : public Person
{
public:
    Doctor();
    Doctor(string name);
    Doctor(string name, int age);
    void add_insurance(string);
    bool accept_insurance(string) const;
    string to_string() const;
private:
    vector<std::string> insurances;
};
#endif
