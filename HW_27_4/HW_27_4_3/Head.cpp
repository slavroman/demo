#include "Head.h"
#include <iostream>

Head::Head(std::string name)
	:Person(name), mCommand(0)
{
}

Head::~Head()
{
}

void Head::setCommand()
{
	size_t command = 0;

	std::cout << "Please type positive digital command:\n";
	std::cin >> command;

	while (command <= 0)
	{
		std::cout << "Incorrect input, please try again!\n";
		std::cin >> command;
	}

	mCommand = command;
}

size_t Head::getCommand()
{
	return mCommand;
}