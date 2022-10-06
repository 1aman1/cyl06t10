class Solution
{
    int ROW, COL;
    // vector<vector<bool>> visited;
    const vector<int> directions = {0, 1, 0, -1, 0};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        ROW = grid.size();
        COL = grid[0].size();

        queue<pair<int, int>> myQ;
        int countFresh = 0, timeToRot = 0;

        // visited.resize(ROW);
        // for (int r = 0; r < ROW; ++r)
        //     visited[r].resize(COL);

        for (int r = 0; r < ROW; ++r)
        {
            for (int c = 0; c < COL; ++c)
            {
                if (grid[r][c] == 1)
                    ++countFresh;
                else if (grid[r][c] == 2)
                    myQ.emplace(r, c);
                else
                    ;
            }
        }

        if (!countFresh)
            return 0;

        while (!myQ.empty())
        {
            ++timeToRot;

            for (int neighbours = myQ.size(); neighbours > 0; --neighbours)
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

                    if (grid[r][c] != 1)
                        continue;

                    // if (visited[r][c])
                    //     continue;

                    grid[r][c] = 2;
                    myQ.emplace(r, c);
                    --countFresh;
                    // visited[r][c] = true;
                }
            }
        }

        return countFresh == 0 ? timeToRot - 1 : -1;
    }
};