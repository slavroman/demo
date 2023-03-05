#include "Manager.h"
#include <ctime>

Manager::Manager(std::string name)
	:Person(name), mManagerID(mID + 1)
{
}

Manager::~Manager()
{
}

size_t Manager::getManagerID()
{
	return mManagerID;
}