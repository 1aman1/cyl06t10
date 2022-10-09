class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		std::vector<std::vector<int>> cache(row, std::vector<int>(col, 1));

		for (int r = 1; r < row; ++r)
			for (int c = 1; c < col; ++c)
				cache[r][c] = cache[r - 1][c] + cache[r][c - 1];

		return cache[row - 1][col - 1];
	}
};
