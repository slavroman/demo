#include "Worker.h"
#include <iostream>
#include <ctime>

Worker::Worker(std::string name)
	:Person(name), mTask(TaskType::NONE)
{
}

Worker::~Worker()
{
}

void Worker::setTaskToWorker()
{
	std::srand((size_t)std::time(nullptr));

	size_t min = static_cast<size_t>(TaskType::A);
	size_t max = static_cast<size_t>(TaskType::C);

	mTask = static_cast<TaskType>(min + (rand() % static_cast<int>(max - min + 1)));
}

bool Worker::checkWorkerBusy()
{
	return static_cast<bool>(mTask);
}

std::string Worker::printTypeOfWorkerTask()
{
	std::string result = "";

	switch (mTask)
	{
	/*case TaskType::NONE:
		break;*/
	case TaskType::A:
		result = "A";
		break;
	case TaskType::B:
		result = "B";
		break;
	case TaskType::C:
		result = "C";
		break;
	/*default:
		break;*/
	}

	return result;
}
