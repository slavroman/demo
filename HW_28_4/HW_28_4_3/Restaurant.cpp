#include "Restaurant.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

Restaurant::Restaurant()
	:mOrderStatus(Status::IDLE)
{
}

Restaurant::~Restaurant()
{
}

void Restaurant::kitchen()
{	
	std::unique_lock<std::mutex> uniqueLock(mOrder);
	std::cout << "ID: " << std::this_thread::get_id() << ": kitchen() STARTED\n";

	mOrderReady.wait(uniqueLock, [=]()
	{
		return mOrderStatus == Status::NEW_ORDER;
	});

	std::srand((int)std::time(nullptr));
	auto min{ 5 }, max{ 15 };
	auto idx = min + (rand() % static_cast<int>(max - min + 1));

	std::cout << "Kitchen: cooking the order ("<< idx <<" sec.)...\n";
	std::this_thread::sleep_for(std::chrono::seconds(idx));
	
	mOrderStatus = Status::READY;
	std::cout << "Kitchen: order is ready!!!\n";
	mOrderReady.notify_one();
	std::cout << "ID: " << std::this_thread::get_id() << ": kitchen() STOPPED\n";
}

void Restaurant::courier()
{	
	std::cout << "ID: " << std::this_thread::get_id() << ": courier() STARTED\n";
	{
		std::unique_lock<std::mutex> uniqueLock(mOrder);
		mOrderStatus = Status::NEW_ORDER;
		std::cout << "Courier: send a new order.\n";
		mOrderReady.notify_one();
	}
	// out of its scope, mOrder.unlock()

	std::unique_lock<std::mutex> uniqueLock(mOrder);

	mOrderReady.wait(uniqueLock, [=]()
	{
		(mOrderStatus == Status::READY) ? std::cout << "Courier: order is delivered!\n" : std::cout << "Courier: waiting when order will ready...\n";
		return mOrderStatus == Status::READY;
	});

	std::cout << "ID: " << std::this_thread::get_id() << ": courier() STOPPED\n";
} // out of its scope, mOrder.unlock()