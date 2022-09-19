#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>

int getRandomNumber(int, int);

int main()
{
	std::srand((size_t)std::time(nullptr));

	std::cout << getRandomNumber(3, 5) << "\n";

	return 0;
}

int getRandomNumber(int min, int max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}