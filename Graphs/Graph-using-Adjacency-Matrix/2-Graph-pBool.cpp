/*
graph
*/

#include <iostream>
#include <vector>

class Graph
{
private:
    bool **_graph;

    int row;
    int col;

    void _build_graph();

public:
    Graph(int row, int col) : row(row), col(col)
    {
        _build_graph();
    }

    ~Graph()
    {
        delete[] _graph;
        std::cout << "\nreleased the newly allocated memory\n";
    }

    void print();

    void fill(std::vector<std::vector<int>> &connections);
};

void Graph::_build_graph()
{
    _graph = new bool *[row];
    for (int i = 0; i < row; ++i)
    {
        _graph[i] = new bool[row];
    }
}

void Graph::print()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            std::cout << _graph[row][col] << " ";
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
    Graph obj(4, 4);

    std::vector<std::vector<int>> connections{{0, 1},
                                              {1, 2},
                                              {2, 0},
                                              {3, 2}};

    obj.fill(connections);

    obj.print();

    return 0;
}