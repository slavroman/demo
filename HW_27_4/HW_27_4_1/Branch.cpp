#include <iostream>
#include <cassert>
#include "branch.h"

Branch::Branch()
    : elfName("Unknown"), parent(nullptr), childrensCount(0), neighbours(0)
{
}

Branch::~Branch()
{
}

void Branch::addChild(Branch* child)
{
    childrens.push_back(child);
}

void Branch::setElfName()
{
    std::string name = "";
    std::cout << "Please enter elf's name:\n";
    std::cin >> name;

    assert(!name.empty());
    elfName = name;
}

void Branch::setParent(Branch* ptrParent)
{
    parent = ptrParent;
}

void Branch::setNeighbours(size_t number)
{
    neighbours = number;
}

void Branch::setChildrensCount(size_t number)
{
    childrensCount = number;
}

Branch* Branch::getChild(size_t number)
{
    if (number < 0 || number >= childrens.size())
    {
        std::cerr << "The number is out of range!!!\n";
        return;
    }

    return childrens[number];
}

std::string Branch::getElfName()
{
    return elfName;
}

Branch* Branch::getParent()
{
    return parent;
}

size_t Branch::getNeighbours()
{
    return neighbours;
}

size_t Branch::getChildrensCount()
{
    return childrensCount;
}

Branch* Branch::getTopBranch()
{
    if (parent == nullptr)
    {
        return nullptr;
    }

    if (parent->parent == nullptr)
    {
        return parent;
    }
    // if a small branch
    return parent->getTopBranch();    
}
