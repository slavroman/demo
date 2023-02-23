#include "Manager.h"

Manager::Manager(std::string name, size_t id, size_t teamId)
	:Person(name), mID(id), Team(teamId)
{
}

Manager::~Manager()
{
}

size_t Manager::getManagerId()
{
	return mID;
}
