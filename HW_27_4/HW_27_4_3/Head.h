#pragma once
#include "Person.h"

class Head :
    public Person
{
public:
    Head(std::string);
    ~Head();

    void setCommand(int);

private:
    int mCommand;
};

