#include "Team.h"
#include <iostream>

Team::Team()
    : mTeamID(ID + 1)
{
}

Team::~Team()
{
}

void Team::addWorkersInTeam(size_t workersCount)
{
    if (workersCount)
    {
        for (size_t i = 0; i < workersCount; ++i)
        {
            std::shared_ptr<Worker> worker = std::make_shared<Worker>("Worker#" + std::to_string(++i));
            mWorkers.push_back(worker);

        }
    }
    else
    {
        std::cout << "Team hasn't workers!";
    }    
}

size_t Team::getWorkersCount()
{
    return mWorkers.size();
}

size_t Team::getTeamId()
{
    return mTeamID;
}
