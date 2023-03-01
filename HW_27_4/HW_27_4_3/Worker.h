#pragma once
#include "Person.h"

class Worker :
    public Person
{
public:
    Worker(std::string);
    ~Worker();
    
    bool checkWirkerBusy();
};

