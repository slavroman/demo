#include "Train.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	std::cout << "Task 2.\n";

	Train trainA("A", 6);
	Train trainB("B", 8);
	Train trainC("C", 12);

	std::thread t1(&Train::move, std::ref(trainA));
	std::thread t2(&Train::move, std::ref(trainB));
	std::thread t3(&Train::move, std::ref(trainC));

	t1.join();
	t2.join();
	t3.join();

	return 0;
}