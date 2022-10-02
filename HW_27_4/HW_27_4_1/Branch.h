#pragma once
#include <string>
#include <vector>

class Branch
{
public:
    Branch();

private:
    std::string elfName;
    bool tenant;
    Branch* parent;
    std::vector<Branch*> children;
};

