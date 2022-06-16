class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; ++i)
        {
            matrix[i].resize(n);
        }

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int number = 1;
        int nSQ = n * n;
        while (number <= nSQ)
        {
            for (int i = left; i <= right; ++i)
            {
                matrix[top][i] = number;
                ++number;
            }
            ++top;

            for (int i = top; i <= bottom; ++i)
            {
                matrix[i][right] = number;
                ++number;
            }
            --right;

            for (int i = right; i >= left; --i)
            {
                matrix[bottom][i] = number;
                ++number;
            }
            --bottom;

            for (int i = bottom; i >= top; --i)
            {
                matrix[i][left] = number;
                ++number;
            }
            ++left;
        }
        return matrix;
    }
};