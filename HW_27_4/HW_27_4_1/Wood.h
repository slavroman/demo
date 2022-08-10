#pragma once
#include <string>

class ElfHouse
{
public:
	ElfHouse();

private:
	int elfCount;
	std::string elfName;
};

class Branch
{
public:

	Branch* getTopBranch();

private:
	int largeBranch;
	int midleBranch;
};

