#include <iostream>
#include <string>
#include "Track.h"
#include "Player.h"

int main()
{
	std::srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "Task 1.\n";

	Player MyPlayer;

	std::string input = "";

	do
	{
		std::cout << "Please inter command:\n";
		std::cin >> input;

		while (input != "add" && input != "play" && input != "pause" &&
			   input != "next" && input != "stop" && input != "exit" &&
			   input != "list")
		{
			std::cout << "The command is incorrect! Please try again:\n";
			std::cin >> input;
		}

		std::cin.ignore();

		if (input == "add")
		{
			int day = 0, month = 0, year = 0, lenght = 0;

			std::cout << "Please enter the track name:\n";
			std::getline(std::cin, input);

			std::cout << "Please enter the song data(day, month, year):\n";
			std::cin >> day >> month >> year;

			std::cout << "Please enter the song lenght in seconds:\n";
			std::cin >> lenght;

			Track obj(input, day, month, year, lenght);

			MyPlayer.addTrack(obj);
		}

		if (input == "play")
		{
			std::cout << "Please enter the track name:\n";
			std::getline(std::cin, input);

			MyPlayer.play(input);

		}

		if (input == "pause")
		{
			MyPlayer.pause();
		}

		if (input == "next")
		{
			MyPlayer.next();
		}

		if (input == "stop")
		{
			MyPlayer.stop();
		}

		if (input == "list")
		{
			MyPlayer.showTracklist();
		}

	} while (input != "exit");

	return 0;
}