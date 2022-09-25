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
    for (auto Row = _graph.begin(); Row != _graph.end(); ++Row)
    {
        (*Row).resize(0);
    }
}

void Graph::_build_graph()
{
    _graph.resize(_row);

    for (auto Row = _graph.begin(); Row != _graph.end(); ++Row)
        (*Row).resize(_col);
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

class Solution : public Graph
{
    std::vector<std::vector<bool>> _visited;

public:
    Solution(int Row, int Col) : Graph(Row, Col)
    {
        _build_visited();
    }

    int
    smallest_island();

private:
    int this_island_size = 0;
    int min_island = 9999;

    bool
    explore_land(int, int);

    void
    _build_visited();
};

void Solution::_build_visited()
{
    _visited.resize(_row);

    for (auto Row = _visited.begin(); Row != _visited.end(); ++Row)
        (*Row).resize(_col);
}

int Solution::smallest_island()
{
    for (int r = 0; r < _row; ++r)
    {
        for (int c = 0; c < _col; ++c)
        {
            if (explore_land(r, c))
            {
                min_island = std::min(min_island, this_island_size);

                this_island_size = 0;
            }
        }
    }

    return min_island;
}

bool Solution::explore_land(int Row, int Col)
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
    ++this_island_size;

    // tried to optimize when we found an island bigger than previous,in that case control doesn't need to continue calculating it's full size, we can pre-emptively return the control from there.

    explore_land(Row + 1, Col);
    explore_land(Row - 1, Col);
    explore_land(Row, Col + 1);
    explore_land(Row, Col - 1);

    return true;
}

int main()
{
    int _row = 6;
    int _col = 5;

    Solution obj(_row, _col);

    std::vector<std::vector<int>> connections{
        {0, 1}, {1, 1}, {2, 3}, {3, 2}, {3, 3}, {4, 0}, {4, 3}, {4, 4}, {5, 0}, {5, 1}};

    obj.fill(connections);

    obj.print();

    std::cout << obj.smallest_island();

    return 0;
}