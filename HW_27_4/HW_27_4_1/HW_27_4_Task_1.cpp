#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <array>
#include "branch.h"

int randomInt(int min, int max);

int main()
{
	std::srand((size_t)std::time(nullptr));

	const int trees = 5;

	Branch Wood[trees];

	for (size_t i = 0; i < trees; i++)
	{

	}

	return 0;
}

int randomInt(int min, int max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}