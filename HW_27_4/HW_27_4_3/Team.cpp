#include "Team.h"
#include <iostream>

Team::Team(std::string managerName)
    :mManager(std::make_shared<Manager>(managerName)), mTaskCount(0), mTeamBusy(false)
{
}

Team::~Team()
{
}

void Team::addWorkersInTeam(size_t workersCount)
{
    if (workersCount > 0)
    {
        for (size_t i = 0; i < workersCount; ++i)
        {
            auto worker = std::make_shared<Worker>("Worker #" + std::to_string(++i));
            mWorkers.push_back(worker);
        }
    }
    else
    {
        std::cout << "Team hasn't workers!";
    }    
}

void Team::setTaskCount(size_t command)
{
    auto result = command + mManager->getManagerID();
    std::srand(result);

    std::cout << "Manager " << mManager->getPersonName() 
              << " with ID " << mManager->getManagerID() 
              << " got a task " << command << " fot team.\n";

    mTaskCount = rand() % (getWorkersCount() + 1);
}

void Team::assignTaskToWorkers()
{    
    auto it = std::find_if(mWorkers.begin(), mWorkers.end(), [](std::shared_ptr<Worker> w) { return w->checkWorkerBusy(); });

    if (it != mWorkers.end())
    {
        (*it)->setTaskToWorker();

        std::cout << (*it)->getPersonName() << " got a task " << (*it)->printTypeOfWorkerTask() << ".\n";
    }
    else
    {
        mTeamBusy = true;
        std::cout << "All workers in " << mManager->getPersonName() << "'s team received tasks!!!\n";
    }
}

size_t Team::getWorkersCount()
{
    return mWorkers.size();
}

size_t Team::getTaskCount()
{
    return mTaskCount;
}

bool Team::getTeamBusyStatus()
{
    return mTeamBusy;
}