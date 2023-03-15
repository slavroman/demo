#pragma once
#include <string>

class Train
{
public:
	Train(std::string, size_t);
	~Train();

private:
	std::string mName;
	size_t mTravelTime;

};