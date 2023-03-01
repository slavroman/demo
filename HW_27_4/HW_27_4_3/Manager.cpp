#include "Manager.h"
#include <ctime>

Manager::Manager(std::string name, size_t id, size_t teamId)
	:Person(name), Team()
{
}

Manager::~Manager()
{
}

size_t Manager::setTask(size_t command, size_t teamID)
{
	//TODO: fix task function
	size_t result = command + teamID;
	return std::rand(result);
}
