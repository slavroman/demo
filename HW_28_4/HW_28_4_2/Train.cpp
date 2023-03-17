#include "Train.h"
#include <iostream>
#include <chrono>
#include <thread>


Train::Train(char name, size_t time)
	:mName(name), mTravelTime(time)
{
}

Train::~Train()
{
}

char Train::getName()
{
	return mName;
}

size_t Train::getTime()
{
	return mTravelTime;
}