#include "ListGraph.h"
#include <iostream>

ListGraph::ListGraph()
{
}

ListGraph::ListGraph(IGraph* other)
{
	if (other->VerticesCount() > VerticesCount())
	{
		m_adjacencyList.resize(other->VerticesCount());
	}

	for (size_t i = 0; i < VerticesCount(); i++)
	{
		std::vector<int> vertices;

		other->GetNextVertices(i + 1, vertices);

		for (size_t j = 0; j < vertices.size(); j++)
		{
			AddEdge(i + 1, vertices[j]);
		}
	}	
}

void ListGraph::AddEdge(int from, int to)
{
	size_t row{ 0 };

	(from > to) ? row = from : row = to;

	if (m_adjacencyList.size() < row)
	{
		m_adjacencyList.resize(row);
	}	
	
	--from, --to;

	m_adjacencyList[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
	return m_adjacencyList.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const
{
	--vertex;

	if (vertex < 0 || vertex > m_adjacencyList.size())
	{
		std::cout << "Out of range!\n";
	}
	else
	{
		for (const auto& element : m_adjacencyList[vertex])
		{
			vertices.push_back(element + 1);
		}
	}
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const
{
	--vertex;

	if (vertex < 0 || vertex > m_adjacencyList.size())
	{
		std::cout << "Out of range!\n";
	}
	else
	{
		for (size_t i = 0; i < m_adjacencyList.size(); i++)
		{
			for (size_t j = 0; j < m_adjacencyList[i].size(); j++)
			{
				if (m_adjacencyList[i][j] == vertex)
				{
					vertices.push_back(i + 1);
				}				
			}			
		}
	}
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
				std::cout << i + 1 << " -> ";

				for (const auto& element : m_adjacencyList[i])
				{
					std::cout << element + 1 << ' ';
				}

				std::cout << "\n";
			}			
		}
	}
}