#include <iostream>
#include <vector>
#include <unordered_map>

/*

possible ways,
1> count in traditional manner, keep a count using arrray, increase for existing values

2> sort the vector, take the highest freq integer

3> HashMap, substitute for 1st method, instead of storing in array, use unorderedMap

4> moore  algorithm
*/

class Solution
{
public:
    // O(n)
    // Space(n)
    // 11ms
    int majorityElement(std::vector<int> &nums)
    {
        int count = 0;
        int Num = 0;
        for (const auto &values : nums)
        {
            if (count == 0)
                Num = values;
            count += (values == Num ? 1 : -1);
        }

        count = 0;
        for (const auto &values : nums)
        {
            if (values == Num)
                ++count;
        }

        // if (count > nums.size() / 2)
        return Num;
    }
};

int main()
{
    Solution obj;

    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 2, 2, 2, 10};

    std::cout << obj.majorityElement(nums) << std::endl;

    return 0;
}