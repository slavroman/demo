#pragma once
#include <string>

class Train
{
public:
	Train(char, size_t);
	~Train();

	char getName();
	size_t getTime();

private:
	char mName;
	size_t mTravelTime; //seconds
};