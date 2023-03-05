#pragma once

#include "Manager.h"
#include "Worker.h"
#include <vector>
#include <memory>

class Team
{
public:
	Team(std::string);
	~Team();

	void addWorkersInTeam(size_t);
	void setTaskCount(size_t);
	void assignTaskToWorkers();

	size_t getWorkersCount();
	size_t getTaskCount();
	bool getTeamBusyStatus();

private:
	std::shared_ptr<Manager> mManager;
	size_t mTaskCount;
	bool mTeamBusy;
	std::vector< std::shared_ptr<Worker> > mWorkers;	
};