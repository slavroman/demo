#include "Head.h"
#include "Manager.h"
#include "Worker.h"
#include "Team.h"
#include <iostream>

int main()
{
	std::cout << "Task 3.\n";
	
	size_t teamCount = 0;
	std::vector<Team> teams;
	std::string input = "";

	std::cout << "Please input head of company name:\n";
	std::cin >> input;

	Head head(input);

	std::cout << "Please input amount of Teams:\n";
	std::cin >> teamCount;

	while (teamCount <= 0)
	{
		std::cout << "Incorrect input, please try again:\n";
		std::cin >> teamCount;
	}	

	for (size_t i = 0; i < teamCount; ++i)
	{
		size_t workersCount = 0;

		std::cout << "Please input manager name:\n";
		std::cin >> input;

		std::cout << "Please input amount of workers in Team:\n";
		std::cin >> workersCount;

		while (workersCount <= 0)
		{
			std::cout << "Incorrect input, please try again:\n";
			std::cin >> workersCount;
		}

		Team team(input);
		team.addWorkersInTeam(workersCount);
		teams.push_back(team);
	}

	for (size_t i = 0; i < teams.size(); ++i)
	{
		while (!teams[i].getTeamBusyStatus())
		{
			head.setCommand();
			teams[i].setTaskCount(head.getCommand());

			size_t tasks = teams[i].getTaskCount();

			while (tasks !=	0)
			{
				teams[i].assignTaskToWorkers();
				tasks--;
			}
		}
	}

	std::cout << "\n*** END OF PROGRAM!!! ***\n";

	return 0;
}