#include <iostream>
#include "branch.h"

Branch::Branch()
    : elfName("Unknown"), parent(nullptr), childrensCount(0), neighbours(0)
{
}

Branch::~Branch()
{
}

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
