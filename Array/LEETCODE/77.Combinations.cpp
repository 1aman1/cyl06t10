#include <iostream>
#include <vector>

using namespace std;

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
    utility(int n, int k, int scale)
    {
        if (pattern.size() == k)
        {
            result.push_back(pattern);
            return;
        }

        for (int i = scale; i <= n; ++i)
        {
            pattern.push_back(i);
            utility(n, k, i + 1);
            pattern.pop_back();
        }
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> vect = obj.combine(4, 2);

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}