#include "Restaurant.h"
#include <iostream>
#include <thread>

int main()
{
	std::cout << "Task 3.\n";	

	Restaurant restaurant;
    
	std::thread kitchen(&Restaurant::kitchen, std::ref(restaurant));
	std::thread courier(&Restaurant::courier, std::ref(restaurant));

	kitchen.join();
	courier.join();

	return 0;
}