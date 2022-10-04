#pragma once

#include <string>
#include <vector>

class Branch
{
public:
    Branch();
    ~Branch();
    
    void addChild(Branch*);
    void setElfName();
    void setParent(Branch*);
    /*void setNeighbours(size_t);*/
    void setChildrensCount(size_t);

    Branch*     getChild(size_t);
    std::string getElfName();
    Branch*     getParent();    
    size_t      getNeighbours();
    size_t      getChildrensCount();
    Branch*     getTopBranch();

private:
    std::string          elfName;
    Branch*              parent;
    size_t               childrensCount;
    size_t               neighbours;
    std::vector<Branch*> childrens;
};