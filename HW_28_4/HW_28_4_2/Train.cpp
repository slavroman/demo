#include "Train.h"
#include <iostream>
#include <chrono>
#include <thread>


Train::Train(std::string name, size_t time)
	:mName(name), mTravelTime(time)
{
}

Train::~Train()
{
}

std::string Train::getName()
{
	return mName;
}

void Train::move()
{
	size_t time = mTravelTime;

	while (time)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "Train " << mName << " move " << time << " seconds...\n";

		time--;
	}

	arrived();
}

void Train::arrived()
{
	std::lock_guard<std::mutex> guard(mtx);

	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	std::string command{ "" };

	std::cout << "\nTrain " << getName() << " arrived at the station!\n";

	std::cout << "Please input \"depart\" command:\n";
	std::cin >> command;

	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	std::cout << "\nTrain " << getName() << " left the station!\n";
}
