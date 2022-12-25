#pragma once

#include <string>
#include <vector>

class Branch
{
public:
    Branch();
    
    Branch*     getTopBranch();

private:
    std::string          elfName;
    Branch*              parent;    
    std::vector<Branch*> childrens;
};