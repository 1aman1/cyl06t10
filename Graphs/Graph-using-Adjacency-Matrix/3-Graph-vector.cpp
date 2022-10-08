#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Graph
{
    std::vector<std::vector<bool>> _graph;
    int _row, _col;

    void
    _build_graph();

public:
    Graph(int Row, int Col) : _row(Row), _col(Col) { _build_graph(); }

    ~Graph();

    void
    fill(std::vector<std::vector<int>> &connections);

    void print();
};

Graph::~Graph()
{
    for (auto eachRow = _graph.begin(); eachRow != _graph.end(); ++eachRow)
    {
        (*eachRow).resize(0);
    }
    _graph.resize(0);
}

void Graph::_build_graph()
{
    _graph.resize(_row);

    for (auto eachRow = _graph.begin(); eachRow != _graph.end(); ++eachRow)
        (*eachRow).resize(_col);
}

void Graph::print()
{
    for (auto eachRow = _graph.begin(); eachRow != _graph.end(); ++eachRow)
    {
        for (auto Col = (*eachRow).begin(); Col != (*eachRow).end(); ++Col)
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
    int _row = 4;
    int _col = 4;

    Graph obj(_row, _col);

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