#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Graph
{
    std::vector<std::vector<bool>> _graph;
    int row, col;

    void
    _build_graph();

public:
    Graph(int Row, int Col) : row(Row), col(Col) { _build_graph(); }

    ~Graph();

    void
    fill(std::vector<std::vector<int>> &connections);

    void print();
};

Graph::~Graph()
{
    for (auto Row = _graph.begin(); Row != _graph.end(); ++Row)
    {
        (*Row).resize(0);
    }
}

void Graph::_build_graph()
{
    _graph.resize(row);

    for (auto Row = _graph.begin(); Row != _graph.end(); ++Row)
        (*Row).resize(col);
}

void Graph::print()
{
    for (auto Row = _graph.begin(); Row != _graph.end(); ++Row)
    {
        for (auto Col = (*Row).begin(); Col != (*Row).end(); ++Col)
        {
            std::cout << *Col << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::fill(std::vector<std::vector<int>> &connections)
{
    for (size_t r = 0; r < connections.size(); ++r)
    {
        _graph[connections[r][0]][connections[r][1]] = true;
    }
}

int main()
{
    int row = 4;
    int col = 4;

    Graph obj(row, col);

    std::vector<std::vector<int>> connections{{0, 1},
                                              {1, 2},
                                              {2, 3},
                                              {3, 1},
                                              {3, 2},
                                              {2, 0}};

    obj.fill(connections);

    obj.print();

    return 0;
}