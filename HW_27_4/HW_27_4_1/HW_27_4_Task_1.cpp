#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include "branch.h"

int randomInt(int min, int max);

int main()
{
	std::srand((size_t)std::time(nullptr));

	const int treesCount = 5;

	Branch Tree[treesCount];

	for (size_t treeNumber = 0; treeNumber < treesCount; treeNumber++)
	{
		
	}

	return 0;
}

int randomInt(int min, int max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}