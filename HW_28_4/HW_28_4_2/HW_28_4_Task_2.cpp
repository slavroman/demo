#include "Train.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex station;

void railwayStation(Train&);

int main()
{
	std::cout << "Task 2.\n";

	std::string str = "ABC";

	int time[3]{};

	for (size_t i = 0; i < (sizeof(time) / sizeof(*time)); i++)
	{
		int n{ 0 };

		std::cout << "Please input time for train \"" << str[i] << "\":\n";
		std::cin >> n;

		time[i] = n;
	}

	Train trainA(str[0], time[0]);
	Train trainB(str[1], time[1]);
	Train trainC(str[2], time[2]);

	std::thread t1(railwayStation, std::ref(trainA));
	std::thread t2(railwayStation, std::ref(trainB));
	std::thread t3(railwayStation, std::ref(trainC));

	t1.join();
	t2.join();
	t3.join();

	std::cout << "\nAll trains passed.\n";

	return 0;
}

void railwayStation(Train& train)
{
	std::cout << "\nTrain " << train.getName() << " start move!\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(train.getTime()));

	std::cout << "\nTrain " << train.getName() << " is waiting!\n";

	std::lock_guard<std::mutex> guard(station);

	std::cout << "\nTrain " << train.getName() << " arrived at the station!\n";

	std::cout << "Please input \"depart\" command:\n";

	while (true)
	{
		std::string command{ "" };
		
		std::cin >> command;

		if (command == "depart")
		{
			std::cout << "\nTrain " << train.getName() << " left the station!\n";
			break;
		}
	}
}
