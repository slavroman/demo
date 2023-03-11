#include "Swimmer.h"
#include <iostream>
#include <chrono>
#include <thread>

Swimmer::Swimmer(std::string name, double speed)
	:mSwimmerName(name), mSwimSpeed(speed), mSwimDistance(0.0), mSwimTime(mTotalDistance / speed)
{
}

Swimmer::~Swimmer()
{
}

void Swimmer::setDistance()
{
	while (this->getDistance() <= mTotalDistance)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		mSwimDistance += mSwimSpeed;

		//Uncomment for DEBUG messages
		//std::cout << "\nID: " << std::this_thread::get_id() << "\nName: " << this->getName() << "\nDistance: " << this->getDistance() << std::endl;
	}	
}

size_t Swimmer::getTotalDistance()
{
	return mTotalDistance;
}

std::string Swimmer::getName()
{
	return mSwimmerName;
}

double Swimmer::getSpeed()
{
	return mSwimSpeed;
}

double Swimmer::getDistance()
{
	return mSwimDistance;
}

double Swimmer::getTime()
{
	return mSwimTime;
}

void Swimmer::printSwimmerStatus()
{
	std::cout << "\n\t============ INFO ============\n";	

	if (this->getDistance() <= mTotalDistance)
	{		
		std::cout << "\n\tSwimmer " << this->getName() << " swam " << this->getDistance() << " meters\n";
	}
	else
	{
		std::cout << "\n\tSwimmer " << this->getName() << " swam the distance!\n";
	}
	
	std::cout << "\n\t==============================\n";
}