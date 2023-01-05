#pragma once

#include "branch.h"
#include <vector>

class Tree : public Branch
{
public:
    Tree();

    void treeFinder();

private:
    std::vector<Branch*> m_branches;
};