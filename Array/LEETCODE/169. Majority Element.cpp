#include <iostream>
#include <vector>
#include <unordered_map>

/*

possible ways,
1> count in traditional manner, keep a count using arrray, increase for existing values

2> sort the vector, take the highest freq integer

3> HashMap, substitute for 1st method, instead of storing in array, use unorderedMap

4>
*/
class Solution
{
public:
    // O(n)
    // Space(n)
    // 26ms
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> frequency;

        int maxCount = 0, maxInt = -1;
        int majorityCount = nums.size() / 2;

        for (const auto &values : nums)
        {
            ++frequency[values];

            // check if the curr inserted element qualifies for majority pass
            maxCount = frequency[values];
            maxInt = values;

            if (majorityCount < maxCount)
                return maxInt;
            std::cout << "freq\n";
        }

        return maxInt;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 2, 2, 2, 10};

    std::cout << obj.majorityElement(nums) << std::endl;

    return 0;
}