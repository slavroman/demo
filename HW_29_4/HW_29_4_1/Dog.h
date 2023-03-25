#pragma once
#include "Swimming.h"
#include "Dancing.h"
#include "Counting.h"
#include <vector>
#include <string>
#include <memory>

class Dog	
{
public:
	Dog(std::string);
	~Dog();

	virtual void showTalent();

	void addTalent(std::shared_ptr<Talent>);

	std::string getName();
	virtual void showTalents();

private:
	std::string mName;
	std::vector<std::shared_ptr<Talent>> mTalents;
};