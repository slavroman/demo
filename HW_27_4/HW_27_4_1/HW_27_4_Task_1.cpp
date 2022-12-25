#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "branch.h"

size_t randomInit(size_t, size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	

	return 0;
}

size_t randomInit(size_t min, size_t max)
{
    return (min + (rand() % static_cast<int>(max - min + 1)));
}