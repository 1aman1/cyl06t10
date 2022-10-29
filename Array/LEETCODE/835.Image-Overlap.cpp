#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<pair<int, int>> Aones;
        vector<pair<int, int>> Bones;
        unordered_map<int, int> chart;

        const int size = A.size();
        int salt, result;

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                if (A[i][j] == 1)
                    Aones.emplace_back(i, j);
                if (B[i][j] == 1)
                    Bones.emplace_back(i, j);
            }

        salt = 1000;
        for (const pair<int, int> &a : Aones)
            for (const pair<int, int> &b : Bones)
                ++chart[(a.first - b.first) * salt + (a.second - b.second)];

        result = 0;
        for (const auto &[_, value] : chart)
            result = max(result, value);

        return result;
    }
};

int main()
{
    vector<vector<int>> img1 = {{1, 1, 0},
                                {0, 1, 0},
                                {0, 1, 0}};

    vector<vector<int>> img2 = {{0, 0, 0},
                                {0, 1, 1},
                                {0, 0, 1}};

    Solution obj;
    cout << obj.largestOverlap(img1, img2);

    return 0;
}