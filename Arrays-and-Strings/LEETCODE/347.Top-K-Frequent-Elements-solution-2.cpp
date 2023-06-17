#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct numMeta
{
    int num;
    int freq;

    numMeta(int num, int freq) : num(num), freq(freq) {}
};

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        auto custom_compare = [](const numMeta &a, const numMeta &b)
        { return a.freq > b.freq; };

        priority_queue<numMeta, vector<numMeta>, decltype(custom_compare)> minHeap(custom_compare);

        unordered_map<int, int> numberToFreq;
        for (const int num : nums)
        {
            if (numberToFreq.find(num) == numberToFreq.end())
                numberToFreq.insert({num, 1});
            else
                ++numberToFreq[num];
        }

        for (const auto &[num, freq] : numberToFreq)
        {
            minHeap.emplace(num, freq);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        numberToFreq.clear();

        vector<int> result;
        while (!minHeap.empty())
            result.insert(result.begin(), minHeap.top().num), minHeap.pop();

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
        std::cout << itr << std::endl;
    }

    return 0;
}
