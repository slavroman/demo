#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <array>

int randomInt(int min, int max);

int main()
{
	std::srand((size_t)std::time(nullptr));


	return 0;
}

int randomInt(int min, int max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}