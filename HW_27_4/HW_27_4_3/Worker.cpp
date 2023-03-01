#include "Worker.h"

Worker::Worker(std::string name)
	:Person(name)
{
}

Worker::~Worker()
{
}

bool Worker::checkWirkerBusy()
{
	return mTask;
}
