#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        for (int row = 0; row < board.size(); ++row)
            for (int col = 0; col < board[0].size(); ++col)
            {
                if (find_word(board, word, row, col, 0))
                    return true;
            }
        return false;
    }

private:
    bool find_word(std::vector<std::vector<char>> &board, std::string word, int row, int col, int size)
    {
        bool rowCheck = 0 <= row && row < board.size();
        bool colCheck = 0 <= col && col < board[0].size();

        if (!rowCheck || !colCheck)
            return false;

        if (word[size] != board[row][col] || board[row][col] == '+')
            return false;

        if (size == word.size() - 1)
            return true;

        const char visiterTag = board[row][col];
        board[row][col] = '+';

        bool consensus = find_word(board, word, row + 1, col, size + 1) +
                         find_word(board, word, row - 1, col, size + 1) +
                         find_word(board, word, row, col + 1, size + 1) +
                         find_word(board, word, row, col - 1, size + 1);

        board[row][col] = visiterTag;

        return consensus;
    }
};

int main()
{
    Solution obj;

    if (obj.exist())
        cout << "Found\n";

    return 0;
}