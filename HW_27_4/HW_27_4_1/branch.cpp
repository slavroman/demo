#include <iostream>
#include <cassert>
#include "branch.h"

Branch::Branch()
    : m_name("None"), m_parent(nullptr), m_nonEmptyHousesOnBranch(0)
{
}

void Branch::setName()
{
    std::string elfName{ "" };

    std::cout << "Please input elf name:\n";
    std::cin >> elfName;

    while (elfName.empty())
    {
        std::cout << "The elf's name couldn't be empty! Try again:\n";
        std::cin >> elfName;
    }

    if (elfName != "None" && elfName != "none")
    {
        m_name = elfName;
    }
}

void Branch::setParrent(Branch* parrent)
{
    m_parent = parrent;
}

void Branch::addChild(Branch* child)
{
    m_childrens.push_back(child);
}

std::string Branch::getName()
{
    return m_name;
}

size_t Branch::getChildrensCount()
{
    return m_childrens.size();
}

size_t Branch::getCountOfNonEmptyHousesOnBranch()
{
    for (const auto& it : m_childrens)
    {
        if (it->getName() != "None")
        {
            m_nonEmptyHousesOnBranch++;
        }
    };

    return m_nonEmptyHousesOnBranch;
}

Branch* Branch::getTopBranch()
{
    // if tree
    if (m_parent == nullptr)
    {
        return nullptr;
    }

    // if a middle branch
    if (m_parent->m_parent == nullptr)
    {
        return m_parent;
    }
    // if a small branch
    return m_parent->getTopBranch();    
}