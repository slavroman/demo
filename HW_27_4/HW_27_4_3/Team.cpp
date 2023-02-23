#include "Team.h"

Team::Team()
    : mTeamID(ID + 1)
{
}

Team::~Team()
{
}

void Team::addWorkerInTeam(std::unique_ptr<Worker> worker)
{
    mWorkers.push_back(worker);
}

size_t Team::getWorkersCount()
{
    return mWorkers.size();
}

size_t Team::getTeamId()
{
    return mTeamID;
}
