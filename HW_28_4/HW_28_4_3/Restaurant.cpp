#include "Restaurant.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <vector>


Restaurant::Restaurant()
	:mOrderStatus(Status::IDLE), mOrderCount(10), mOrderName("")
{
}

Restaurant::~Restaurant()
{
}

int Restaurant::getRandom(int min, int max)
{
	return (min + (rand() % static_cast<int>(max - min + 1)));
}

void Restaurant::kitchen()
{
	while (true)
	{
		std::unique_lock<std::mutex> uniqueLock(mOrder);
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": kitchen() STARTED\n";

		mOrderReady.wait(uniqueLock, [=]()
		{
			return mOrderStatus == Status::NEW_ORDER;
		});		

		std::vector<std::string> dishes{ "Pizza", "Soup", "Steak", "Salad", "Sushi" };

		auto min{ 0 }, max{ 4 };
		mOrderName = dishes[getRandom(min, max)];

		min = 5, max = 15;
		auto cookingTime = getRandom(min, max);		

		std::cout << "Kitchen: cooking the order - " << mOrderName << " (" << cookingTime << " sec.)...\n";
		std::this_thread::sleep_for(std::chrono::seconds(cookingTime));

		mOrderStatus = Status::READY;
		
		std::cout << "Kitchen: order - " << mOrderName << " is ready!!!\n";
		mOrderReady.notify_all();
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": kitchen() STOPPED\n";
	}	
}

void Restaurant::waiter()
{	
	while (mOrderCount)
	{
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": waiter() STARTED\n";

		std::unique_lock<std::mutex> uniqueLock(mOrder);
		mOrderReady.wait(uniqueLock, [=]()
		{
			return mOrderStatus == Status::IDLE;
		});

		mOrderStatus = Status::NEW_ORDER;
		mOrderCount--;
		std::cout << "waiter: send a new order.\n";
		mOrderReady.notify_all();
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": waiter() STOPPED\n";
	}	
} // out of its scope, mOrder.unlock()

void Restaurant::courier()
{
	while (mOrderCount)
	{
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": courier() STARTED\n";

		std::unique_lock<std::mutex> uniqueLock(mOrder);

		mOrderReady.wait(uniqueLock, [=]()
		{
			/*(mOrderStatus == Status::READY) ? std::cout << "courier: order is delivered!\n" : std::cout << "courier: waiting when order will ready...\n";*/
			return mOrderStatus == Status::READY;
		});

		mOrderStatus = Status::IDLE;
		std::cout << "courier: order - " << mOrderName << " is delivered!\n";
		mOrderReady.notify_all();
		//Uncomment for DEBUG messages
		//std::cout << "ID: " << std::this_thread::get_id() << ": courier() STOPPED\n";
	}	
}
