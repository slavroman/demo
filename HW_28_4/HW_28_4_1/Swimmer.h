#pragma once
#include <string>

class Swimmer
{
public:
	Swimmer(std::string, size_t);
	~Swimmer();

	void setName(std::string);
	void setSpeed(size_t);

	std::string getName();
	size_t getSpeed();

private:
	std::string mSwimmerName;
	size_t mSwimSpeed;
};

