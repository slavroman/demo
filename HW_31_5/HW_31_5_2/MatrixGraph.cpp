#include "MatrixGraph.h"
#include <iostream>

MatrixGraph::MatrixGraph()
{
}

MatrixGraph::MatrixGraph(IGraph* other)
{
	if (other->VerticesCount() > VerticesCount())
	{
		resizeMatrix(other->VerticesCount(), other->VerticesCount());
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

void MatrixGraph::AddEdge(int from, int to)
{
	if (m_matrix.size() < from || m_matrix.size() < to)
	{
		resizeMatrix(from, to);
	}	

	--from, --to;

	m_matrix[from][to] = 1;	
}

int MatrixGraph::VerticesCount() const
{
	return m_matrix.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const
{
	--vertex;

	if (vertex < 0 || vertex > m_matrix.size())
	{
		std::cout << "Out of range!\n";
	}
	else
	{				
		for (size_t i = 0; i < m_matrix.size(); i++)
		{			
			if (m_matrix[vertex][i] > 0)
			{
				vertices.push_back(i + 1);
			}			
		}
	}
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const
{
	--vertex;

	if (vertex < 0 || vertex >  m_matrix.size())
	{
		std::cout << "Out of range!\n";
	}
	else
	{
		for (size_t i = 0; i < m_matrix.size(); i++)
		{

			if (m_matrix[i][vertex] > 0)
			{
				vertices.push_back(i + 1);
			}
		}
	}
}

void MatrixGraph::Show() const
{
	if (m_matrix.empty())
	{
		std::cout << "No matrix!\n";
	}
	else
	{
		for (const auto& row : m_matrix)
		{
			for (const auto& element : row)
			{
				std::cout << element << ' ';
			}

			std::cout << "\n";
		}

		std::cout << "\n";
	}
}

void MatrixGraph::resizeMatrix(int from, int to)
{
	size_t n{ 0 };

	(from > to) ? n = from : n = to;

	m_matrix.resize(n, std::vector<int>());

	for (size_t i = 0; i < n; i++)
	{
		m_matrix[i].resize(n);
	}
}