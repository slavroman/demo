#pragma once
#include"Worker.h"
#include <vector>
#include <memory>

class Team
{
public:
	Team();
	~Team();

	void addWorkerInTeam(std::unique_ptr<Worker>);

	size_t getWorkersCount();
	size_t getTeamId();

private:
	static const size_t ID = 0;
	size_t mTeamID;
	std::vector< std::unique_ptr<Worker> > mWorkers;
};

