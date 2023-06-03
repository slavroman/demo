#pragma once

#include <memory>
#include "IGraph.h"

class MatrixGraph :
    public IGraph
{
public:
    MatrixGraph();
    MatrixGraph(IGraph* other);

    void AddEdge(int from, int to) override;
    int  VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
    void Show() const override;

private:    
    std::vector<std::vector<int>> m_matrix;    
    void resizeMatrix(int from, int to);
};

