#include "Restaurant.h"
#include <iostream>
#include <thread>

int main()
{
	std::cout << "Task 3.\n";

	std::srand((int)std::time(nullptr));

	Restaurant restaurant;
    
	std::thread kitchen(&Restaurant::kitchen, std::ref(restaurant));
	std::thread waiter(&Restaurant::waiter, std::ref(restaurant));
	std::thread courier(&Restaurant::courier, std::ref(restaurant));

	kitchen.detach();
	waiter.join();
	courier.join();

	std::cout << "\nAll orders have been completed!!!\n";

	return 0;
}