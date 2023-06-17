class Solution
{
    const int ROW = 9;
    const int COLUMN = 9;

    bool checkRow(int r, int c, const vector<vector<char>> &board)
    {
        int excommunicado = board[r][c];
        for (int goesRight = c + 1; goesRight < COLUMN; ++goesRight)
        {
            if (board[r][goesRight] == excommunicado)
                return false;
        }
        return true;
    }

    bool checkColumn(int r, int c, const vector<vector<char>> &board)
    {
        int excommunicado = board[r][c];
        for (int goesBelow = r + 1; goesBelow < ROW; ++goesBelow)
        {
            if (board[goesBelow][c] == excommunicado)
                return false;
        }
        return true;
    }

    bool checkInnerBox(int r, int c, const vector<vector<char>> &board)
    {
        int excommunicado = board[r][c];

        int localSquareRowOffset = r - (r % 3);
        int localSquareColOffset = c - (c % 3);

        for (int localRow = localSquareRowOffset; localRow < 3 + localSquareRowOffset; ++localRow)
        {
            for (int localCol = localSquareColOffset; localCol < 3 + localSquareColOffset; ++localCol)
            {
                if (localRow != r && localCol != c)
                {
                    if (board[localRow][localCol] == excommunicado)
                        return false;
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(const vector<vector<char>> &board)
    {
        for (int r = 0; r < ROW; ++r)
        {
            for (int c = 0; c < COLUMN; ++c)
            {
                if (board[r][c] != '.')
                    if (!(checkRow(r, c, board) && checkColumn(r, c, board) && checkInnerBox(r, c, board)))
                        return false;
            }
        }
        return true;
    }
};
