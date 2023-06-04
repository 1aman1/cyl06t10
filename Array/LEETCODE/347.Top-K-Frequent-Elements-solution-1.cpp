#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::map<int, int> numberToFreq;

        for (auto i = 0; i < nums.size(); ++i)
            ++numberToFreq[nums[i]];

        std::vector<std::pair<int, int>> tmpVector;

        for (auto &itr : numberToFreq)
            tmpVector.push_back({itr.first, itr.second});

        sort(tmpVector.begin(), tmpVector.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
             { return a.second > b.second; });

        std::vector<int> result;

        for (int i = 0; i < k; ++i)
            result.push_back(tmpVector[i].first);

        return result;
    }
};

int main()
{
    std::vector<int> nums = {1, 1, 1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution obj;
    std::vector<int> result = obj.topKFrequent(nums, k);

    for (const auto &itr : result)
    {
        std::cout << itr;
    }

    return 0;
}