#include <iostream>
#include <string>
#include "Display.h"
#include "Window.h"

void clearScreen();

int main()
{
	std::cout << "Task 3.\n";

	Display Display1;
	Window Window1;
	std::string input = "";

	do
	{
		std::cout << "\nPlease input a command:\n";
		std::cin >> input;

		while (input != "move" && input != "resize" &&
			   input != "display" && input != "close")
		{
			std::cout << "\nIncorrect command please try again:\n";
			std::cin >> input;
		}

		clearScreen();

		if (input == "move")
		{
			Window1.moveWindow();
		}

		if (input == "resize")
		{
			Window1.setWinsowSize();
		}

		if (input == "display")
		{			
			Display1.showDisplay(Window1);
		}

	} while (input != "close");

	return 0;
}

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}