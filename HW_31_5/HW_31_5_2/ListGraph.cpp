#include "ListGraph.h"
#include <iostream>

ListGraph::ListGraph()
{
}

void ListGraph::AddEdge(int from, int to)
{
	if (m_adjacencyList.size() < from + 1)
	{
		m_adjacencyList.resize(from + 1);
	}	
	
	m_adjacencyList[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
	return m_adjacencyList.size();
}

void ListGraph::Show() const
{
	if (m_adjacencyList.empty())
	{
		std::cout << "No list graph!\n";
	}
	else
	{
		for (size_t i = 0; i < m_adjacencyList.size(); i++)
		{
			if (!m_adjacencyList[i].empty())
			{
				std::cout << i << " -> ";

				for (const auto& element : m_adjacencyList[i])
				{
					std::cout << element << ' ';
				}

				std::cout << "\n";
			}			
		}
	}
}
