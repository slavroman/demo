#pragma once
#include <mutex>
#include <condition_variable>
#include <string>

class Restaurant
{
public:
	Restaurant();
	~Restaurant();

	int getRandom(int, int);
	void kitchen();
	void waiter();
	void courier();

private:
	enum class Status
	{
		IDLE,
		NEW_ORDER,
		READY
	};

	Status mOrderStatus;
	std::mutex mOrder;
	std::condition_variable mOrderReady;
	int mOrderCount;
	std::string mOrderName;
};