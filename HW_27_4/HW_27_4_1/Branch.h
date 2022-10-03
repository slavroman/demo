#pragma once
#include <string>
#include <vector>

class Branch
{
public:
    Branch();
    ~Branch();

    Branch* getTopBranch();

private:
    std::string elfName;
    Branch* parent;
    size_t childrensCount;
    size_t neighbours;
    std::vector<Branch*> childrens;
};

