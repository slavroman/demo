#include "Node.h"
#include <iostream>
#include <ctime>

size_t randomInit(const size_t, const size_t);

int main()
{
	std::srand((size_t)std::time(nullptr));

	std::shared_ptr<Node> tree = std::make_shared<Node>();
	
	

	return 0;
}

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}