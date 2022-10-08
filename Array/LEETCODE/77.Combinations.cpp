class Solution
{
    vector<int> pattern;
    vector<vector<int>> result;

public:
    vector<vector<int>>
    combine(int n, int k)
    {
        utility(n, k, 1);
        return result;
    }

private:
    void
    utility(int N, int K, int scale)
    {
        if (K == pattern.size())
        {
            result.push_back(pattern);
            return;
        }

        for (int i = scale; i <= N; ++i)
        {
            pattern.push_back(i);
            utility(N, K, i + 1);
            pattern.pop_back();
        }
    }
};