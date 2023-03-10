#include "Swimmer.h"

Swimmer::Swimmer(std::string name = "Unknown", size_t speed = 0)
	:mSwimmerName(name), mSwimSpeed(speed)
{
}

Swimmer::~Swimmer()
{
}

void Swimmer::setName(std::string name)
{
	mSwimmerName = name;
}

void Swimmer::setSpeed(size_t speed)
{
	mSwimSpeed = speed;
}

std::string Swimmer::getName()
{
	return mSwimmerName;
}

size_t Swimmer::getSpeed()
{
	return mSwimSpeed;
}
