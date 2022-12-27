#pragma once

#include <string>
#include <vector>

class Branch
{
public:
    Branch();
    
    void setName();
    void setParrent(Branch* parrent);
    void addChild(Branch*);

    std::string getName();   
    size_t      getCountOfNonEmptyHousesOnBranch();
    Branch*     getTopBranch();

private:
    std::string          m_name;
    Branch*              m_parent;
    size_t               m_nonEmptyHousesOnBranch;
    std::vector<Branch*> m_childrens;
};