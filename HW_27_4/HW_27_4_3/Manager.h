#pragma once
#include "Person.h"
#include "Team.h"

class Manager :
    public Person, public Team
{
public:
    Manager(std::string, size_t, size_t);
    ~Manager();

    size_t setTask(size_t, size_t);
};

