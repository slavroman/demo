#include "branch.h"
#include "tree.h"
#include <ctime>

int main()
{
	std::srand((size_t)std::time(nullptr));

	Tree* test1 = new Tree;

	while (true)
	{
		test1->treeFinder();
	}
	

	return 0;
}