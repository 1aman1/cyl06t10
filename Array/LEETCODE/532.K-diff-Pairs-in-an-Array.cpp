#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> cache;

        for (int i = 0; i < nums.size(); ++i)
            cache[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i)
        {
            const int target = nums[i] + k;
            if (cache.count(target) && cache[target] != i)
            {
                ++result;
                cache.erase(target);
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5};
    // std::vector<int> v = {1, 1, 1, 1, 1};

    Solution obj;
    int k = 2;
    std::cout << obj.findPairs(v, k);

    return 0;
}