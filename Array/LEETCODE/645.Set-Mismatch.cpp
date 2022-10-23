#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int duplicate;

        for (const int num : nums)
        {
            if (nums[abs(num) - 1] < 0)
                duplicate = abs(num);
            else
                nums[abs(num) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                return {duplicate, i + 1};
                
        return {};
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {3, 2, 3, 4, 6, 5};

    for (const auto &i : obj.findErrorNums(nums))
        cout << i << ":";

    return 0;
}
