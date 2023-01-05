#pragma once

#include <string>
#include <vector>

class Branch
{
public:
    Branch();    
   
    size_t randomInit(const size_t, const size_t);
    void getChild();
    bool branchFinder(std::string);

private:    
    std::string          m_name;
    bool                 m_tenant;
    bool                 m_parent;
    std::vector<Branch*> m_childrens;
};