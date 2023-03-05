#pragma once
#include "Person.h"

class Head :
    public Person
{
public:
    Head(std::string);
    ~Head();

    void setCommand();

    size_t getCommand();

private:
    size_t mCommand;
};

