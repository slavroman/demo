#include "Branch.h"
#include <iostream>

Branch::Branch()
    :elfName(" "), tenant(false), parent(nullptr)
{
    std::cout << "Enter elf name: ";
    std::cin >> elfName;

    if (elfName != "none" || elfName != " ")
    {
        tenant = true;
    }
}
