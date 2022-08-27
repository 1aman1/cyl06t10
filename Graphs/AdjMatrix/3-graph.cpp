#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<bool>> vec_2d_t;
typedef std::vector<bool> vec_t;

class Graph
{

public:
    Graph(int, int);
    ~Graph();

    void _fill_graph();
    void print_graph();

    bool is_connected(int, int);

private:
    int row;
    int column;

    vec_2d_t _matrix;
    void _build_graph();

    vec_t _visited;
};

Graph::~Graph()
{
    for (auto lens = _matrix.begin(); lens != _matrix.end(); ++lens)
    {
        (*lens).resize(0);
    }
    _visited.resize(0);
}

Graph::Graph(int r, int c)
{
    row = r;
    column = c;

    _build_graph();
}

void Graph::_build_graph()
{
    _matrix.resize(row);

    for (auto lens = _matrix.begin(); lens != _matrix.end(); ++lens)
    {
        (*lens).resize(column);
    }

    // prepare visited
    _visited.resize(row);

    // prepare the connections
    _fill_graph();
}

void Graph::print_graph()
{
    for (auto lens = _matrix.begin(); lens != _matrix.end(); ++lens)
    {
        for (auto n_itr = (*lens).begin(); n_itr != (*lens).end(); ++n_itr)
        {
            std::cout << *n_itr << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::_fill_graph()
{
    _matrix[0][1] = true;
    _matrix[1][2] = true;
    _matrix[2][3] = true;
    _matrix[3][1] = true;
    _matrix[3][2] = true;
    _matrix[2][0] = true;
}

bool Graph::is_connected(int source_row, int target)
{
    if (_visited[source_row] == false)
    {
        _visited[source_row] = true;

        std::cout << "current " << source_row << ":" << target << "\n";

        int key = 1;
        int occurs_1 = 0;
        auto lens = std::find(_matrix[source_row].begin() + occurs_1, _matrix[source_row].end(), key);

        while (lens != _matrix[source_row].end())
        {
            if (target == lens - _matrix[source_row].begin())
            {
                std::cout << "connected\n";
                return true;
            }

            std::cout << "searching further in the " << source_row << " level\n";

            is_connected(lens - _matrix[source_row].begin(), target);
            occurs_1 += lens - _matrix[source_row].begin() + 1;
            lens = std::find(_matrix[source_row].begin() + occurs_1, _matrix[source_row].end(), key);
        }
    }
}

int main()
{
    int row = 4;
    int column = 4;

    Graph obj(row, column);

    obj.print_graph();

    obj.is_connected(1, 1);

    return 0;
}