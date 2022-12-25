#include <iostream>
#include <cassert>
#include "branch.h"



Branch* Branch::getTopBranch()
{
    if (parent == nullptr)
    {
        return nullptr;
    }

    if (parent->parent == nullptr)
    {
        return parent;
    }
    // if a small branch
    return parent->getTopBranch();    
}