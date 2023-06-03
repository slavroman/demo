#pragma once

#include "IGraph.h"
#include <vector>

class ListGraph :
    public IGraph
{
public:
    ListGraph();
    ListGraph(IGraph* other);

    void AddEdge(int from, int to) override;
    int  VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
    void Show() const override;

private:
    std::vector<std::vector<int>> m_adjacencyList;
};