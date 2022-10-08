#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Graph
{
protected:
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

class Solution : public Graph
{
    std::vector<std::vector<bool>> _visited;

public:
    Solution(int Row, int Col) : Graph(Row, Col)
    {
        _build_visited();
    }

    int
    get_island_count();

private:
    bool
    _explore_land(int, int);

    void
    _build_visited();
};

void Solution::_build_visited()
{
    _visited.resize(_row);

    for (auto eachRow = _visited.begin(); eachRow != _visited.end(); ++eachRow)
        (*eachRow).resize(_col);
}

int Solution::get_island_count()
{
    int total_islands = 0;

    for (int r = 0; r < _row; ++r)
    {
        for (int c = 0; c < _col; ++c)
        {
            if (_explore_land(r, c))
            {
                ++total_islands;
            }
        }
    }

    return total_islands;
}

bool Solution::_explore_land(int Row, int Col)
{
    bool rowCheck = 0 <= Row && Row < _row;
    bool colCheck = 0 <= Col && Col < _col;

    if (!rowCheck || !colCheck)
        return false;

    // check for water
    if (_graph[Row][Col] == false)
        return false;

    if (_visited[Row][Col])
        return false;

    _visited[Row][Col] = true;

    _explore_land(Row + 1, Col);
    _explore_land(Row - 1, Col);
    _explore_land(Row, Col + 1);
    _explore_land(Row, Col - 1);

    return true;
}

int main()
{
    int _row = 4;
    int _col = 5;

    Solution obj(_row, _col);

    std::vector<std::vector<int>> connections{
        {0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1}, {1, 3}, {2, 0}, {2, 1}};

    obj.fill(connections);

    obj.print();

    std::cout << obj.get_island_count();

    return 0;
}