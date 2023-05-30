// Test
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main()
{
	std::cout << "Task 2.\n";

	std::cout << "----------------Test1----------------\n";
	std::cout << "ListGraph -> MatrixGraph -> ListGraph\n";
	IGraph* a = new ListGraph;
	a->AddEdge(1, 2);
	a->AddEdge(1, 3);
	a->AddEdge(3, 1);
	a->AddEdge(10, 11);

	std::cout << "-----------ListGraph-----------\n";
	a->Show();

	std::cout << "----------MatrixGraph----------\n";
	IGraph* d = new MatrixGraph(a);
	d->Show();

	std::cout << "-----------ListGraph-----------\n";
	IGraph* c = new ListGraph(d);
	c->Show();

	return 0;
};