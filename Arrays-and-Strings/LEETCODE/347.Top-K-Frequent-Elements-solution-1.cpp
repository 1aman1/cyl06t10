#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::map<int, int> numberToFreq;
        vector<pair<int, int>> placeHolderForSortedFreq;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (numberToFreq.find(nums[i]) == numberToFreq.end())
                numberToFreq.insert({nums[i], 1});
            else
                ++numberToFreq[nums[i]];
        }

        for (const auto &itr : numberToFreq)
            placeHolderForSortedFreq.push_back({itr.first, itr.second});

        numberToFreq.clear();

        sort(begin(placeHolderForSortedFreq), end(placeHolderForSortedFreq),
             [](const pair<int, int> &left, const pair<int, int> &right)
             { return left.second > right.second; });

        for (int i = 0; i < k; ++i)
            result.push_back(placeHolderForSortedFreq[i].first);

        return result;
    }
};

int main()
{
    std::vector<int> nums = {3, 0, 1, 0};
    int k = 1;
    Solution obj;
    std::vector<int> result = obj.topKFrequent(nums, k);

    for (const auto &itr : result)
    {
        std::cout << itr;
    }

    return 0;
}