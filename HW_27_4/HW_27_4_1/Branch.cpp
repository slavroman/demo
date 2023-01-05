#include "branch.h"
#include <iostream>
#include <ctime>

Branch::Branch()
    : m_name("None"), m_tenant(false), m_parent(false)
{
    std::cout << "Enter elf name:\n";
    std::cin >> m_name;

    while (m_name.empty())
    {
        std::cout << "The elf's name couldn't be empty! Try again:\n";
        std::cin >> m_name;
    }

    if (m_name != "None" && m_name != "none")
    {
        m_tenant = true;
    }
}

size_t Branch::randomInit(const size_t min, const size_t max)
{
    return (min + (rand() % static_cast<int>(max - min + 1)));
}

void Branch::getChild()
{
    if (this->m_parent == false)
    {
        for (size_t i = 0; i < randomInit(2, 3); ++i)
        {
            Branch* middleBranch = new Branch;
            middleBranch->m_parent = true;
            m_childrens.push_back(middleBranch);
        }
    }
}

bool Branch::branchFinder(std::string request)
{
    if (request == this->m_name)
    {
        std::cout << request << " have " << this->m_childrens.size() + 1 << " neighbors" << std::endl;
        return true;
    }

    for (size_t i = 0; i < m_childrens.size(); ++i)
    {
        if (request == m_childrens[i]->m_name)
        {
            if (this->m_tenant)
            {
                std::cout << request << " have " << this->m_childrens.size() + 1 << " neighbors" << std::endl;
                return true;
            }
            else
            {
                std::cout << request << " have " << this->m_childrens.size() << " neighbors" << std::endl;
                return true;
            }
        }
    }

    return false;
}

