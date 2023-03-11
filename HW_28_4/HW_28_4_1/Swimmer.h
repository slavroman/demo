#pragma once
#include <string>

class Swimmer
{
public:
	Swimmer(std::string, double);
	~Swimmer();
			
	void setDistance();

	size_t getTotalDistance();
	std::string getName();
	double getSpeed();
	double getDistance();
	double getTime();
	void printSwimmerStatus();

private:
	static const size_t mTotalDistance{ 100 };
	std::string mSwimmerName;
	double mSwimSpeed;
	double mSwimDistance;
	double mSwimTime;
};