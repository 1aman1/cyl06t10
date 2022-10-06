class Solution
{
    vector<vector<bool>> visited;
    int _row, _col;

public:
    int maxAreaOfIsland(vector<vector<int>> &image)
    {
        _row = image.size();
        _col = image[0].size();
        int max_island = 0;

        visited.resize(_row);
        for (int i = 0; i < visited.size(); ++i)
            visited[i].resize(_col);

        for (int r = 0; r < _row; ++r)
        {
            for (int c = 0; c < _col; ++c)
            {
                int size = _explore_land(r, c, image);
                max_island = std::max(max_island, size);
            }
        }
        return max_island;
    }

private:
    int _explore_land(int Row, int Col, vector<vector<int>> &image)
    {
        bool rowCheck = 0 <= Row && Row < _row;
        bool colCheck = 0 <= Col && Col < _col;

        if (!rowCheck || !colCheck)
            return 0;

        // check for water
        if (image[Row][Col] == false)
            return 0;

        if (visited[Row][Col])
            return 0;

        visited[Row][Col] = true;
        int size = 1;

        size += _explore_land(Row + 1, Col, image);
        size += _explore_land(Row - 1, Col, image);
        size += _explore_land(Row, Col + 1, image);
        size += _explore_land(Row, Col - 1, image);

        return size;
    }
};