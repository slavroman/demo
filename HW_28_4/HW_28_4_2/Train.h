#pragma once
#include <string>
#include <mutex>

class Train
{
public:
	Train(std::string, size_t);
	~Train();

	std::string getName();
	void move();
	void arrived();

private:
	std::mutex mtx;
	std::string mName;
	size_t mTravelTime; //seconds
};