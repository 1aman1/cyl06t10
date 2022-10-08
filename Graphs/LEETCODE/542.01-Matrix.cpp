class Solution
{
    int ROW, COL;
    vector<vector<bool>> visited;
    const vector<int> directions = {0, 1, 0, -1, 0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        ROW = grid.size();
        COL = grid[0].size();
        queue<pair<int, int>> myQ;

        visited.resize(ROW);
        for (int r = 0; r < ROW; ++r)
            visited[r].resize(COL);

        for (int r = 0; r < ROW; ++r)
        {
            for (int c = 0; c < COL; ++c)
            {
                if (grid[r][c] == 0)
                {
                    myQ.emplace(r, c);
                    visited[r][c] = true;
                }
            }
        }

        while (!myQ.empty())
        {
            const auto [i, j] = myQ.front();
            myQ.pop();

            for (int k = 0; k < 4; ++k)
            {
                int r = i + directions[k];
                int c = j + directions[k + 1];

                bool rowCheck = 0 <= r && r < ROW;
                bool colCheck = 0 <= c && c < COL;

                if (!rowCheck || !colCheck)
                    continue;

                if (visited[r][c])
                    continue;

                grid[r][c] = grid[i][j] + 1;
                visited[r][c] = true;
                myQ.emplace(r, c);
            }
        }

        return grid;
    }
};