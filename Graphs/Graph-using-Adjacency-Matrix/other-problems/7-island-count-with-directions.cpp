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
    ~Solution();

    int
    get_cluster_count();

private:
    bool
    _explore_land(int, int, int);

    void
    _build_visited();

    void
    _reset_visited();

    enum class _directions
    {
        HORIZONTAL,
        VERTICAL,
        DIAGONAL,
        HORIZONTAL_VERTICAL,
        VERTICAL_HORIZONTAL_DIAGONAL
    };
};

Solution::~Solution()
{
    for (auto eachRow = _visited.begin(); eachRow != _visited.end(); ++eachRow)
        (*eachRow).resize(0);
    _visited.resize(0);
}

void Solution::_reset_visited()
{
    for (int i = 0; i < _row; ++i)
        std::fill(_visited[i].begin(), _visited[i].end(), false);
}

void Solution::_build_visited()
{
    _visited.resize(_row);

    for (auto eachRow = _visited.begin(); eachRow != _visited.end(); ++eachRow)
        (*eachRow).resize(_col);
}

int Solution::get_cluster_count()
{

    int total_clusters = 0;
    int clusters;

    // HORIZONTAL = 1
    // VERTICAL = 2
    // DIAGONAL = 3
    // HORIZONTAL_VERTICAL = 4
    // VERTICAL_HORIZONTAL_DIAGONAL = 5

    for (int _directions = 1; _directions <= 5; ++_directions)
    {
        clusters = 0;
        _reset_visited();

        for (int r = 0; r < _row; ++r)
        {
            for (int c = 0; c < _col; ++c)
            {
                if (_explore_land(r, c, _directions))
                {
                    ++clusters;
                }
            }
        }

        std::cout << _directions << " direction"
                  << " clusters : " << clusters << "\n";

        total_clusters += clusters;
    }
    return total_clusters;
}

bool Solution::_explore_land(int Row, int Col, int _directions)
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

    switch (_directions)
    {
    case 1:
        _explore_land(Row, Col + 1, _directions);
        _explore_land(Row, Col - 1, _directions);
        break;

    case 2:
        _explore_land(Row + 1, Col, _directions);
        _explore_land(Row - 1, Col, _directions);
        break;

    case 3:
        _explore_land(Row + 1, Col + 1, _directions);
        _explore_land(Row - 1, Col - 1, _directions);
        _explore_land(Row - 1, Col + 1, _directions);
        _explore_land(Row + 1, Col - 1, _directions);
        break;

    case 4:
        _explore_land(Row, Col + 1, _directions);
        _explore_land(Row, Col - 1, _directions);
        _explore_land(Row + 1, Col, _directions);
        _explore_land(Row - 1, Col, _directions);
        break;

    case 5:
        _explore_land(Row, Col + 1, _directions);
        _explore_land(Row + 1, Col, _directions);
        _explore_land(Row + 1, Col + 1, _directions);
        _explore_land(Row - 1, Col - 1, _directions);
        _explore_land(Row - 1, Col + 1, _directions);
        _explore_land(Row + 1, Col - 1, _directions);
        break;
    }

    return true;
}

int main()
{
    int _row = 5;
    int _col = 5;

    Solution obj(_row, _col);

    std::vector<std::vector<int>> connections{
        {0, 0}, {0, 4}, {1, 1}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 3}, {4, 0}, {4, 4}};

    obj.fill(connections);

    obj.print();

    std::cout << obj.get_cluster_count() << "\n";

    return 0;
}