#include "tree.h"
#include <iostream>
#include <ctime>

Tree::Tree()
{
    for (size_t i = 0; i < randomInit(3, 5); ++i)
    {
        Branch* bigBranche = new Branch;
        bigBranche->getChild();
        m_branches.push_back(bigBranche);
    }
}

void Tree::treeFinder()
{
    std::string answer;
    std::cout << "Enter name of elf which you want to find:\n";
    std::cin >> answer;

    for (size_t i = 0; i < m_branches.size(); ++i)
    {
        if (m_branches[i]->branchFinder(answer))
        {
            break;
        }
    }
}
