#include "Head.h"
#include "Manager.h"
#include "Worker.h"
#include "Team.h"
#include <iostream>
#include <ctime>

size_t randomInit(const size_t min, const size_t max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}

int main()
{
	std::cout << "Task 3.\n";

	std::srand((size_t)std::time(nullptr));

	size_t teamsCount{ 0 }, workersInTeamCount{ 0 };

	return 0;
}