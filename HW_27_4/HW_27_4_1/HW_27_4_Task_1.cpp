#include <iostream>
#include <ctime>

size_t randomInit(const size_t, const size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	
	

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}