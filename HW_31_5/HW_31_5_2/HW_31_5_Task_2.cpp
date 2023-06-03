// Test
/* 
     | 1 | 2 | 3 | 4 | 5 |    FROM    |     TO     |
   --+---+---+---+---+---|            |            |
   1 | 0 | 1 | 0 | 1 | 0 |  1 -> 2, 4 |  1 <- 0    |
   --+---+---+---+---+---|            |            |
   2 | 0 | 0 | 1 | 0 | 1 |  2 -> 3, 5 |  2 <- 1    |
   --+---+---+---+---+---|            |            |
   3 | 0 | 0 | 0 | 1 | 0 |  3 -> 4    |  3 <- 2, 5 |
   --+---+---+---+---+---|            |            |
   4 | 0 | 0 | 0 | 0 | 0 |  4 -> 0    |  4 <- 1, 3 |
   --+---+---+---+---+---|            |            |
   5 | 0 | 0 | 1 | 0 | 0 |  5 -> 3    |  5 <- 2    |
*/ 
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

void testObject(IGraph*, int, int);

int main()
{
	std::cout << "Task 2.\n";

	std::cout << "----------------Test1----------------\n";
	std::cout << "ListGraph -> MatrixGraph -> ListGraph\n";
	std::cout << "\n-----------ListGraph-----------\n";
	IGraph* a = new ListGraph;
	a->AddEdge(1, 2);
	a->AddEdge(1, 4);
	a->AddEdge(2, 3);
	a->AddEdge(2, 5);
	a->AddEdge(3, 4);
	a->AddEdge(5, 3);	

	a->Show();

	/*testObject(a, 1, 2);
	testObject(a, 5, 3);*/
	
	std::cout << "\n----------MatrixGraph----------\n";
	IGraph* d = new MatrixGraph(a);

	d->Show();

	/*testObject(d, 1, 2);
	testObject(d, 5, 3);*/

	std::cout << "\n-----------ListGraph-----------\n";
	IGraph* c = new ListGraph(d);

	c->Show();

	/*testObject(c, 1, 2);
	testObject(c, 5, 3);*/

	return 0;
};

void testObject(IGraph* obj, int from, int to)
{
	std::vector<int> testVec;
	std::cout << "\nGetNextVertices() from " << from << ":\n";
	obj->GetNextVertices(from, testVec);	
	std::cout << from << " -> ";
	for (const auto& v : testVec)
	{
		std::cout << v << ' ';
	}

	std::cout << '\n';

	std::vector<int> testVec2;
	std::cout << "\nGetPrevVertices() to " << to << ":\n";
	obj->GetPrevVertices(to, testVec2);	
	std::cout << to << " <- ";
	for (const auto& v : testVec2)
	{
		std::cout << v << ' ';
	}

	std::cout << '\n';

	std::cout << "\nVerticesCount = " << obj->VerticesCount() << '\n';
}