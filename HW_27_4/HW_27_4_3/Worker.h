#pragma once
#include "Person.h"

enum class TaskType
{
    NONE,
    A,
    B,
    C
};

class Worker :
    public Person
{
public:
    Worker(std::string);
    ~Worker();
    
    void setTaskToWorker();
    bool checkWorkerBusy();
    std::string printTypeOfWorkerTask();

private:
    TaskType mTask;
};

