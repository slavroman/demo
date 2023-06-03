// Abstract graph interface

#pragma once
#include <vector>

class IGraph
{
public:
    IGraph()
    {}

    IGraph(IGraph* other)
    {}

    virtual ~IGraph()
    {}

    virtual void AddEdge(int from, int to)                                     = 0;
    virtual int  VerticesCount() const                                         = 0;
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
    virtual void Show() const                                                  = 0;
};