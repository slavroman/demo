#pragma once
#include "Person.h"
#include "Head.h"
#include <ctime>

class Manager :
    public Person
{
public:
    Manager(std::string);
    ~Manager();
        
    size_t getManagerID();

private:
    static const size_t mID = 0;
    size_t mManagerID;
};

