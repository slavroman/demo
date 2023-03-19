#pragma once
#include <mutex>
#include <condition_variable>

class Restaurant
{
public:
	Restaurant();
	~Restaurant();

	void kitchen();
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
};