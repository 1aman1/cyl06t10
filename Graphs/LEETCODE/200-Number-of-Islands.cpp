class Solution
{
    int _row;
    int _col;

    vector<vector<bool>> visited;

    bool explore_land(int Row, int Col, vector<vector<char>> &grid)
    {
        bool rowCheck = 0 <= Row && Row < _row;
        bool colCheck = 0 <= Col && Col < _col;

        if (!rowCheck || !colCheck)
            return false;

        if (grid[Row][Col] == '0')
            return false;

        if (visited[Row][Col])
            return false;

        visited[Row][Col] = true;

        explore_land(Row + 1, Col, grid);
        explore_land(Row - 1, Col, grid);
        explore_land(Row, Col + 1, grid);
        explore_land(Row, Col - 1, grid);

        return true;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int total_islands = 0;

        _row = grid.size();
        _col = grid[0].size();

        visited.resize(_row);
        for (int i = 0; i < _row; ++i)
            visited[i].resize(_col);

        for (int i = 0; i < _row; ++i)
        {
            for (int j = 0; j < _col; ++j)
            {
                if (explore_land(i, j, grid))
                    ++total_islands;
            }
        }
        return total_islands;
    }
};