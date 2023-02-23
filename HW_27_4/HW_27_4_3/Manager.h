#pragma once
#include "Person.h"
#include "Team.h"

class Manager :
    public Person, public Team
{
public:
    Manager(std::string, size_t, size_t);
    ~Manager();

    size_t getManagerId();

private:
    size_t mID;
};

